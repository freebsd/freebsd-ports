# Ports collection makefile for:  Nic
# Date created:			  Sun Dec 30, 2001
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	nic
PORTVERSION=	0.0.2.011230
CATEGORIES=	net www
MASTER_SITES=	http://pompo.net/horde/nic/

MAINTAINER=	thierry@pompo.net

RUN_DEPENDS=	${LOCALBASE}/www/horde/index.php:${PORTSDIR}/www/horde2

NO_BUILD=	yes

USE_REINPLACE=	yes

DOCS=		LICENSE README docs/CHANGES docs/CREDITS docs/INSTALL
CONFFILE=	conf.php html.php menu.php

LHORDEDIR?=	www/horde
LNICDIR?=	${LHORDEDIR}/nic

PLIST_SUB=	HORDEDIR=${LHORDEDIR} NICDIR=${LNICDIR}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
NICDIR=		${PREFIX}/${LNICDIR}
CONFDIR=	${NICDIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde

do-install:
	@${MKDIR}  ${NICDIR}
	@${CP} -Rp ${WRKSRC}/config ${WRKSRC}/graphics ${WRKSRC}/lib ${NICDIR}
	@${CP} -Rp ${WRKSRC}/templates ${NICDIR}
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
	@${REINPLACE_CMD} -e "s://UNCOMMENTWHENINSTNIC::" \
		${HORDEDIR}/config/registry.php
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
