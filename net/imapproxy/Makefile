# Ports collection makefile for:  imapproxy
# Date created:                   Mon July 28, 2003
# Whom:                           Lasse L. Johnsen (lasse@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	imapproxy
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.freebsdcluster.org/~lasse/software/  \
		${MASTER_SITE_LOCAL}

MAINTAINER=	lasse@freebsdcluster.org
COMMENT=	ImapProxy is a caching IMAP proxy daemon to be used with Horde/IMP

GNU_CONFIGURE=	yes
HAS_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/example.conf ${PREFIX}/etc/imapproxy.conf.dist

.include <bsd.port.mk>
