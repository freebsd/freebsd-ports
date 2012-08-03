# New ports collection makefile for:	rinetd
# Date created:				23 Dec 1997
# Whom:					alexp
#
# $FreeBSD$
#

PORTNAME=	rinetd
PORTVERSION=	0.62
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.boutell.com/rinetd/http/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	rinetd

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A simple TCP port redirector

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

WRKSRC=		${WRKDIR}/rinetd/

MAKE_JOBS_SAFE=	yes
USE_DOS2UNIX=	yes

MAN8=		rinetd.8
PORTDOCS=	index.html
PLIST_FILES=	sbin/rinetd

USE_RC_SUBR=	rinetd.sh

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -E "s,(/etc/rinetd.conf),${PREFIX}\1," \
		${WRKSRC}/rinetd.[8c]
	@${REINPLACE_CMD} -E "s,/usr(/sbin/rinetd),${PREFIX}\1," \
		${WRKSRC}/rinetd.8
	@${REINPLACE_CMD} -e "s/cc /${CC} /g" ${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
