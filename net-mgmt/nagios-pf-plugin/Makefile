# Created by: Kian Mohageri <kian.mohageri@gmail.com>
# $FreeBSD$

PORTNAME=	nagios-pf-plugin
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.zampanosbits.com/check_pf/ \
		http://restek.wwu.edu/~kian/
DISTNAME=	check_pf-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios plugin for checking PF

NAGIOS_PLUGIN_DIR?=	libexec/nagios/

PLIST_FILES=	${NAGIOS_PLUGIN_DIR}/check_pf
PLIST_DIRS=	${NAGIOS_PLUGIN_DIR}
SUB_FILES=	pkg-message
SUB_LIST=	NAGIOS_PLUGIN_DIR=${NAGIOS_PLUGIN_DIR}

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You can redefine the following additional variables:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	NAGIOS_PLUGIN_DIR=${NAGIOS_PLUGIN_DIR}"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The plugin directory is relative to PREFIX:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	PREFIX=${PREFIX}"
	@${ECHO_MSG} ""

post-patch:
	${REINPLACE_CMD} -e \
	    "s,/usr/local/libexec/nagios,${PREFIX}/${NAGIOS_PLUGIN_DIR}," \
	    ${WRKSRC}/Makefile

pre-su-install:
	@${MKDIR} ${PREFIX}/${NAGIOS_PLUGIN_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
