# New ports collection Makefile for:	FreeBSD::Portindex
# Date created:		5 Nov 2004
# Whom:			Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$

PORTNAME=	FreeBSD-Portindex
PORTVERSION=	1.4
CATEGORIES=	sysutils perl5
MASTER_SITES=	http://www.infracaninophile.co.uk/portindex/
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	Incremental FreeBSD ports INDEX file generation

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
PERL_CONFIGURE=	yes

CACHE_DIR?=	/var/db/portindex
CACHE_OWNER?=	root
CACHE_GROUP?=	operator
CACHE_MODE?=	0775

CFG_FILE=	portindex.cfg

MAN1=		find-updated.1 cache-init.1 cache-update.1 portindex.1

.include <bsd.port.pre.mk>

##
## Needs a recent version of perl, preferably 5.8.6, but 5.6.1 should work
##
.if ${PERL_LEVEL} < 500601
IGNORE=		Port requires perl 5.6.x or (preferably) later.  Install lang/perl5.8 and try again
.endif

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
.endif

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

.include <bsd.port.post.mk>
