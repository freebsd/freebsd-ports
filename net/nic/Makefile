# Ports collection makefile for:  Nic
# Date created:			  Sun Dec 30, 2001
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	nic
PORTVERSION=	0.0.2.011230
PORTREVISION=	1
CATEGORIES=	net www
MASTER_SITES=	http://pompo.net/horde/nic/

MAINTAINER=	thierry@pompo.net
COMMENT=	Nic is a set of small web-based network applications

RUN_DEPENDS=	${LOCALBASE}/www/horde/index.php:${PORTSDIR}/www/horde2

NO_BUILD=	yes

USE_REINPLACE=	yes

REINPLACE_ARGS=	-i.beforeNic
DOCS=		LICENSE README docs/CHANGES docs/CREDITS docs/INSTALL
CONFFILE=	conf.php html.php menu.php
SUB_DIRS=	config graphics lib templates

LHORDEDIR?=	www/horde
LNICDIR?=	${LHORDEDIR}/nic

PLIST_SUB=	HORDEDIR=${LHORDEDIR} NICDIR=${LNICDIR}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
NICDIR=		${PREFIX}/${LNICDIR}
CONFDIR=	${NICDIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde

do-install:
	@${MKDIR}  ${NICDIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${NICDIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${NICDIR}
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${CHOWN} -R www:www ${NICDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${CP} -p ${FILESDIR}/httpd.conf.nic ${HORDE_INC}
	@${REINPLACE_CMD} -e "s:/home/httpd/html/horde/nic:${NICDIR}:g" \
		${HORDE_INC}/httpd.conf.nic
	@${RM} ${HORDE_INC}/httpd.conf.nic.beforeNic
	@${REINPLACE_CMD} -e "s://UNCOMMENTWHENINSTNIC::" \
		${HORDEDIR}/config/registry.php
	@${CP} -p ${HORDEDIR}/config/registry.php \
		${HORDEDIR}/config/registry.php.afterNic
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | \
		${SED} -e "s:%%NICDIR%%:${NICDIR}:g;s:%%CONFDIR%%:${CONFDIR}:g"
	@${ECHO_MSG}

.include <bsd.port.mk>
