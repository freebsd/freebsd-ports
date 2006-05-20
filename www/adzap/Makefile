# New ports collection makefile for:	adzap
# Date created:		03 March 2001
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	adzap
PORTVERSION=	20060424
CATEGORIES=	www perl5
MASTER_SITES=	http://adzapper.sourceforge.net/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=kris

MAINTAINER=	kris@FreeBSD.org
COMMENT=	Filter out animated ad banners from web pages

WRKSRC=		${WRKDIR}/adzap

NO_BUILD=	yes
USE_PERL5_RUN=	yes

SUB_FILES=	adzap.conf pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

do-configure:
.for FILE in squid_redirect wrapzap
	${REINPLACE_CMD} -e "s:/usr/bin/perl:${PERL5}:g" \
			-e "s:%%PREFIX%%:${PREFIX}:g" ${WRKSRC}/scripts/${FILE}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/squid_redirect ${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/wrapzap ${PREFIX}/libexec/adzap
	${INSTALL} -d ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/zaps ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/rc ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/adzap.conf ${EXAMPLESDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
