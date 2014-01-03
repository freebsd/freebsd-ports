# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vimpager
PORTVERSION=	1.8.3
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/rkitover/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Use ViM as a pager

RUN_DEPENDS=	vim:${PORTSDIR}/editors/vim

OPTIONS_DEFINE=	VIMCAT BASH_DEVEL
OPTIONS_DEFAULT=VIMCAT
VIMCAT_DESC=	Install vimcat(1) (requires shells/bash)
BASH_DEVEL_DESC=Use shells/bash-devel instead of shells/bash

PLIST_FILES=	bin/${PORTNAME} etc/${PORTNAME}rc man/man1/${PORTNAME}.1.gz

VIMCAT_PLIST_FILES=	bin/vimcat man/man1/vimcat.1.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVIMCAT}
.  if ${PORT_OPTIONS:MBASH_DEVEL}
RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash-devel
.  else
RUN_DEPENDS+=	bash:${PORTSDIR}/shells/bash
.  endif
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vimcat ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/vimcat.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}rc ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
