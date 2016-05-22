# Created by: Christian Brueffer <chris@unixpages.org)
# $FreeBSD$

PORTNAME=	ldapdiff
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://launchpadlibrarian.net/20391352/
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for patching LDAP directories using LDIF files

LICENSE=	GPLv3+

USES=		iconv tar:tgz
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${LOCALBASE} \
		--with-ldap-dir=${LOCALBASE}
SAMPLES=	addentry.sh webtomware_without_jpeg.user.ldif \
		webtomware.init.ldif webtomware.user.ldif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	CHANGES ChangeLog README TODO

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ! empty(ICONV_LIB)
CONFIGURE_ARGS+=--with-iconv-dir=${LOCALBASE}
.endif

post-extract:
	@cd ${WRKSRC} && ${RM} -f *.o ldapdiff Makefile config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldapdiff ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ldapdiff.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/ldapdiff.conf.sample ${STAGEDIR}${PREFIX}/etc/
	@${MKDIR} ${STAGEDIR}${DATADIR}/samples
.for sample in ${SAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${sample} ${STAGEDIR}${DATADIR}/samples
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
