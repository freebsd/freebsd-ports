# New ports collection makefile for:	privoxy+ipv6
# Date created:				17 June 2003
# Whom:					Lars Eggert
#
# $FreeBSD$
#

PORTNAME=	privoxy+ipv6
PORTVERSION=	20030523
PORTREVISION=	2
CATEGORIES=	www ipv6
MASTER_SITES=	ftp://ftp.deepspace6.net/pub/ds6/sources/privoxy/
DISTNAME=	privoxy_CVS_${PORTVERSION}_ipv6_5

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Privoxy is a web proxy with advanced filtering capabilities

WRKSRC=		${WRKDIR}/privoxy

ETCDIR=		${PREFIX}/etc/privoxy
USER=		nobody
GROUP=		nobody
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/+ipv6//}

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOHEADER_VER=213
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-user=${USER} --with-group=${GROUP} \
		--sysconfdir=${ETCDIR} --localstatedir=/var

MAKEFILE=	GNUmakefile

MAN1=		privoxy.1

post-install:
	@for file in config user.action; do \
		if [ ! -f ${ETCDIR}/$$file ]; then \
			${CP} ${ETCDIR}/$$file.sample ${ETCDIR}/$$file; \
			${CHOWN} ${USER}:${GROUP} ${ETCDIR}/$$file; \
			${CHMOD} ug+rw ${ETCDIR}/$$file; \
		fi; \
	done

.include <bsd.port.mk>
