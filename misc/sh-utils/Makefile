# New ports collection makefile for:	sh-utils
# Date created:				10 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	sh-utils
PORTVERSION=	2.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR= sh-utils

MAINTAINER=	cyrille.lefevre@laposte.net

# Global variables
#

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g

USE_GMAKE=	yes
# PREFIX isn't honored. force it w/ prefix.
MAKE_ARGS=	prefix=${PREFIX}

MAN1=	gbasename.1 gchroot.1 gdate.1 gdirname.1 gecho.1 genv.1 \
	gexpr.1 gfalse.1 ggroups.1 ghostid.1 ghostname.1 gid.1 \
	glogname.1 gnice.1 gnohup.1 gpathchk.1 gpinky.1 gprintenv.1 \
	gprintf.1 gpwd.1 gsleep.1 gstty.1 gsu.1 gtee.1 gtest.1 \
	gtrue.1 gtty.1 guname.1 gusers.1 gwho.1 gwhoami.1 gyes.1

# Local variables
#

INSTALL_INFO?=	install-info

# Post-extract
#

post-extract: remove-info-files

remove-info-files:
	@${RM} -f ${WRKSRC}/doc/${PORTNAME}.info*

# Patch
#

do-patch:
.if !defined(WITH_SUID)
	@${PERL} -pi -e "s/u\+s/u\+w/g" ${WRKSRC}/src/Makefile.in
.endif

# Post-install
#

post-install: install-info

install-info:
	@${INSTALL_INFO} ${PREFIX}/info/${PORTNAME}.info ${PREFIX}/info/dir

.include <bsd.port.mk>
