# Ports collection makefile for:	libsexymm
# Date created:				2005-11-07
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=		libsexymm
PORTVERSION=		0.1.3
CATEGORIES=		x11-toolkits devel
MASTER_SITES=		http://osiris.chipx86.com/projects/libsexy/releases/

MAINTAINER=		andreas@syndrom23.de
COMMENT=		C++ bindings for libsexy

LIB_DEPENDS=		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
			sexy:${PORTSDIR}/x11-toolkits/libsexy

USE_GNOME=		gnomehack
USE_AUTOTOOLS=		libtool:15:inc
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
INSTALLS_SHLIB=		yes
USE_X_PREFIX=		yes
USE_GCC=		3.4

patch-autotools::
	@(cd ${PATCH_WRKSRC}; \
	for file in ${LIBTOOLFILES}; do \
		${CP} $$file $$file.tmp; \
		${SED} -e "/^ltmain=/s^\$$ac_aux_dir/ltmain.sh^${LTMAIN}^g" \
			$$file.tmp > $$file; \
		${RM} $$file.tmp; \
	done);

.include <bsd.port.mk>
