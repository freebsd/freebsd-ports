# New ports collection makefile for:	porttools
# Date created:		2003-06-18
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	porttools
PORTVERSION=	0.16
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergei@kolobov.com
COMMENT=	Tools for testing and submitting port updates and new ports

RUN_DEPENDS=	portlint:${PORTSDIR}/devel/portlint \
		sudo:${PORTSDIR}/security/sudo

NO_BUILD=	yes
MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	  	INSTALL_DATA="${INSTALL_DATA}"

post-install:
	@${ECHO_MSG} "* * * WARNING * * * WARNING * * *"
	@${ECHO_MSG} "Read ${DOCSDIR}/README before proceeding"
	@${ECHO_MSG} "Report all problems to ${MAINTAINER}"

.include <bsd.port.mk>
