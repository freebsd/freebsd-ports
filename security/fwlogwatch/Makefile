# Created by: ijliao
# $FreeBSD$

PORTNAME=	fwlogwatch
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.kybs.de/boris/sw/

MAINTAINER=	michael@ranner.eu
COMMENT=	Packet filter and firewall log analyzer

USES=		gettext
USE_BZIP2=	yes
MAKE_ENV=	MKDIR="${MKDIR}"
INSTALL_TARGET=	install install-config install-i18n

MAN8=	fwlogwatch.8

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,/etc,${PREFIX}/etc,g" ${WRKSRC}/${MAN8}

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/fwlogwatch.sh.sample ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
