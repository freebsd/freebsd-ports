# New ports collection makefile for:        iplog
# Date created:		4 Oct 1999
# Whom:			Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	iplog
PORTVERSION=	2.2.3
PORTREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://misc.ojnk.net/~odin/stuff/
MASTER_SITE_SUBDIR=	ojnk

MAINTAINER=	udo.schweigert@siemens.com

USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

MAN5=	iplog.conf.5
MAN8=	iplog.8

.include <bsd.port.pre.mk>
post-patch:
.for file in example-iplog.conf iplog.8 iplog.conf.5 src/iplog.h
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/example-iplog.conf ${PREFIX}/etc
.if !exists(${PREFIX}/etc/iplog.conf)
	${INSTALL_DATA} ${WRKSRC}/example-iplog.conf ${PREFIX}/etc/iplog.conf
.endif
.if exists(${PREFIX}/etc/iplog.rules)
	@${ECHO_MSG}
	@${ECHO_MSG} "============================================================================"
	@${ECHO_MSG} "Hint:	iplog changed its configuration file from ${PREFIX}/etc/iplog.rules"
	@${ECHO_MSG} "	to ${PREFIX}/etc/iplog.conf"
	@${ECHO_MSG}
	@${ECHO_MSG} "See ${PREFIX}/etc/example-iplog.conf for an example"
	@${ECHO_MSG} "============================================================================"
.endif
	@${ECHO_MSG}
	@${ECHO_MSG} "Installing ${PREFIX}/etc/rc.d/iplog.sh.sample file."
	@${CAT} ${FILESDIR}/iplog.sh.tmpl | \
		${SED} -e 's;PREFIX;${PREFIX};' \
		> ${PREFIX}/etc/rc.d/iplog.sh.sample
	@${CHMOD} 555 ${PREFIX}/etc/rc.d/iplog.sh.sample
	@${ECHO_MSG} "----------------------------------------------------------------------------"
	@${ECHO_MSG} "If you want iplog to be run as a daemon then do:"
	@${ECHO_MSG} "cp -p ${PREFIX}/etc/rc.d/iplog.sh.sample ${PREFIX}/etc/rc.d/iplog.sh"
	@${ECHO_MSG} "----------------------------------------------------------------------------"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
