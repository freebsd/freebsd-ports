# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	clamd
PORTREVISION=	0

COMMENT=	ClamAV based antivirus plugin for Claws Mail

RUN_DEPENDS=	clamd:${PORTSDIR}/security/clamav

CLAWS_PLUGINS_BUILD=	clamd

post-install:
	@${ECHO}
	@${ECHO_CMD} "********************************************************************************"
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} "********************************************************************************"
	@${ECHO}

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
