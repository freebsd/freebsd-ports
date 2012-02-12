# New ports collection makefile for:	xapian-omega10
# Date created:		05 Jul 2008
# Whom:			Henrik Brix Andersen <brix@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xapian-omega10
PORTVERSION=	1.0.23
CATEGORIES=	www
MASTER_SITES=	http://oligarchy.co.uk/xapian/${PORTVERSION}/
DISTNAME=	${PORTNAME:S/10$//}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CGI search application built on Xapian

LICENSE=	GPLv2

LIB_DEPENDS=	xapian.21:${PORTSDIR}/databases/xapian-core10

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PERL5_RUN=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		omindex.1 scriptindex.1

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/10$//}
WWWDIR=		${PREFIX}/www/${PORTNAME:S/10$//}

MORE_PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
PORTDOCS=	cgiparams.html omegascript.html overview.html \
		quickstart.html scriptindex.html termprefixes.html \
		${MORE_PORTDOCS}
PORTEXAMPLES=	omega.conf

OPTIONS=	ICONV "Enable iconv character set conversion support" On

PORTSCOUT=	limit:^1\.0\.

.include <bsd.port.pre.mk>

.if defined(WITH_ICONV)
USE_ICONV=	yes
CONFIGURE_ARGS+=	--with-iconv
.else
CONFIGURE_ARGS+=	--without-iconv
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|^\(dist_sysconf_DATA\ =\ omega\.conf\)|#\1|' \
		-e "s|^\(pkglibbindir\)\ =.*/bin|\1\ =\ \$$(prefix)/${WWWDIR_REL}/cgi-bin|" \
		 ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} \
		-e 's|^\(SUBDIRS\ =\ \.\) docs|\1|' \
		 ${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${MORE_PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S@^@${WRKSRC}/@} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
