# Created by: ijliao
# $FreeBSD$

PORTNAME=	fwlogwatch
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.kybs.de/boris/sw/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Packet filter and firewall log analyzer

USES=		gettext tar:bzip2
MAKE_ENV=	MKDIR="${MKDIR}"
INSTALL_TARGET=	install install-config install-i18n

post-patch:
	@${REINPLACE_CMD} -e "s,/etc,${PREFIX}/etc,g" ${WRKSRC}/fwlogwatch.8

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/fwlogwatch.sh.sample \
		${STAGEDIR}${PREFIX}/etc/rc.d

.include <bsd.port.mk>
