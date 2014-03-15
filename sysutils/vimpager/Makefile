# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=		vimpager
PORTVERSION=	1.8.7
CATEGORIES=		sysutils
MASTER_SITES=	http://github.com/rkitover/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=		adamw@FreeBSD.org
COMMENT=		Use ViM as a pager

LICENSE=		BSD2CLAUSE

RUN_DEPENDS=	vim:${PORTSDIR}/editors/vim

OPTIONS_DEFINE=		VIMCAT
OPTIONS_DEFAULT=	VIMCAT
VIMCAT_DESC=		Install vimcat(1) (requires shells/bash)
VIMCAT_RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash
VIMCAT_PLIST_FILES=	bin/vimcat man/man1/vimcat.1.gz

PLIST_FILES=		bin/${PORTNAME} etc/${PORTNAME}rc man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vimcat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/vimcat.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}rc ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
