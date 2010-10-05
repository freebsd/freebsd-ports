# New ports collection makefile for:	mod_rivet
# Date created:				June 16, 2010
# Whom:					Peter Lai <cowbert@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mod_rivet
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	www tcl
MASTER_SITES=		${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	tcl/rivet
DISTNAME=		rivet-${PORTVERSION}

MAINTAINER=	cowbert@gmail.com
COMMENT=	Embeds a Tcl interpreter in the Apache server

WRKSRC=			${WRKDIR}/rivet-${PORTVERSION}

MAKE_JOBS_SAFE=	yes

USE_APACHE=	2.2+
USE_AUTOTOOLS=	automake:111 autoconf:267
USE_TCL=	84+
GMAKE=		yes

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--with-apache-version=2 \
			--prefix=${PREFIX} --with-apxs=${APXS} \
			--with-tcl=${TCL_LIBDIR} --with-tclsh=${TCLSH} \
			--with-rivet-target-dir=${PREFIX}/lib/rivet

pre-configure:
	@${ECHO_MSG} "Update dist install-sh with one from automake..."
	${CP} -f ${AUTOMAKE_DIR}/install-sh ${WRKSRC}/tclconfig/install-sh
	cd ${WRKSRC} && ${AUTORECONF} -v

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "===================================================="
	@${ECHO_MSG} "Remember to modify your apache configuration file
	@${ECHO_MSG} "to load mod_rivet:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "LoadModule mod_rivet ${APACHEMODDIR}/mod_rivet.so"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Visit http://tcl.apache.org/rivet/ for documentation"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "===================================================="

.include <bsd.port.post.mk>
