# New ports collection makefile for:        iplog
# Date created:		4 Oct 1999
# Whom:			Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	iplog
PORTVERSION=	2.2.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://misc.ojnk.net/~odin/stuff/
MASTER_SITE_SUBDIR=	ojnk

MAINTAINER=	ust@cert.siemens.de

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN5=	iplog.conf.5
MAN8=	iplog.8

.include <bsd.port.pre.mk>
post-patch:
.for file in example-iplog.conf iplog.8 iplog.conf.5 src/iplog.h
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/example-iplog.conf ${PREFIX}/etc
.if !exists(${PREFIX}/etc/iplog.conf)
	${INSTALL_DATA} ${WRKSRC}/example-iplog.conf ${PREFIX}/etc/iplog.conf
.else
	@${ECHO_MSG}
	@${ECHO_MSG} "============================================================================"
	@${ECHO_MSG} "Hint:	iplog changed its configuration file from ${PREFIX}/etc/iplog.rules"
	@${ECHO_MSG} "	to ${PREFIX}/etc/iplog.conf"
	@${ECHO_MSG}
	@${ECHO_MSG} "See ${PREFIX}/etc/example-iplog.conf for an example"
	@${ECHO_MSG} "============================================================================"
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
