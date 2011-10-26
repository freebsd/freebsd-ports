# New ports collection Makefile for:	FreeBSD::Portindex
# Date created:		5 Nov 2004
# Whom:			Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$

PORTNAME=	FreeBSD-Portindex
PORTVERSION=	2.6
CATEGORIES=	ports-mgmt perl5
MASTER_SITES=	http://www.infracaninophile.co.uk/portindex/
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	Incremental FreeBSD ports INDEX file generation

LICENSE=	BSD

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB
RUN_DEPENDS:=	${BUILD_DEPENDS}

# GraphViz not required for portindex to run or generate GraphViz
# format output: this is only needed to render the output on the same
# machine.
OPTIONS=	GRAPHVIZ "Add GraphViz run-time dependency" off

.include <bsd.port.options.mk>

.if defined(WITH_GRAPHVIZ) && !defined(WITHOUT_GRAPHVIZ)
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.endif

USE_XZ=	yes
PERL_CONFIGURE=	yes

CACHE_DIR?=	/var/db/portindex
CACHE_OWNER?=	root
CACHE_GROUP?=	operator
CACHE_MODE?=	0775

CFG_FILE=	portindex.cfg

MAN1=		find-updated.1 cache-init.1 cache-update.1 portindex.1 \
		portdepends.1

post-install: install-conf install-cache

install-conf:
	cd ${WRKSRC} ; \
	${INSTALL_DATA} ${CFG_FILE}.sample ${PREFIX}/etc/${CFG_FILE}.sample
	cd ${PREFIX}/etc ; \
	if ${TEST} ! -f ${CFG_FILE} ; then \
	    ${CP} -p ${CFG_FILE}.sample ${CFG_FILE} ; \
	fi

# Create the cache directory and make it writable by group 'operator'
# by default.  Only if the cache directory doesn't already exist.
# Have to do this by hand if installing via pkg.

install-cache:
	if ${TEST} ! -d ${CACHE_DIR} ; then \
	    ${MKDIR} ${CACHE_DIR} ; \
	    ${CHOWN} ${CACHE_OWNER}:${CACHE_GROUP} ${CACHE_DIR} ; \
	    ${CHMOD} ${CACHE_MODE} ${CACHE_DIR} ; \
	fi

.include <bsd.port.mk>
