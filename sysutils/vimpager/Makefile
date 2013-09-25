# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vimpager
PORTVERSION=	1.8.2
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/rkitover/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Use ViM as a pager

RUN_DEPENDS=	vim:${PORTSDIR}/editors/vim

FETCH_ARGS=	-prR

PLIST_FILES=	bin/${PORTNAME} bin/vimcat etc/${PORTNAME}rc man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vimcat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}rc ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
