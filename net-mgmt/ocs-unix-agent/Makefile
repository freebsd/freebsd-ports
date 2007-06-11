# New ports collection makefile for:    ocs-unix-agent
# Date created: 8 May 2007
# Whom:         Dennis Cabooter
#
# $FreeBSD$
#

PORTNAME=	ocs-unix-agent
PORTVERSION=	0.7
CATEGORIES=	net-mgmt
MASTER_SITES=	http://bfleisch.free.fr/ocs-solaris-client/

MAINTAINER=	freebsd@rootxs.org
COMMENT=	Keep track of the computers configuration and software

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	libxml2

#NOTES: that's not a mistake it's a bug in configure.
#Author will fix this with next uptream release.
CONFIGURE_ARGS=	--with-zlib=${PREFIW}/usr

PLIST_SUB=	RELEASE=${RELEASE}
PLIST_FILES=	bin/ocs-agent-freebsd-%%RELEASE%% \
		bin/ocs-agent-freebsd-%%RELEASE%%.1007

.include <bsd.port.pre.mk>

RELEASE!=	/usr/bin/uname -r

.include <bsd.port.post.mk>
