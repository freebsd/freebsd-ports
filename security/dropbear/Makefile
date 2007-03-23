# New ports collection makefile for:	dropbear
# Date created:				20 August 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	dropbear
PORTVERSION=	0.49
CATEGORIES=	security ipv6
MASTER_SITES=	http://matt.ucc.asn.au/dropbear/releases/

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	An SSH 2 server, designed to be usable in small memory environments

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

OPTIONS=   STATIC  "Build statically"  off \

.include <bsd.port.pre.mk>

.if defined(WANT_STATIC) || defined(WITH_STATIC)
CONFIGURE_ENV=	LDFLAGS=-static
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,_PRIV_FILENAME \"/etc/,_PRIV_FILENAME \"${PREFIX}/etc/,g; \
		s,/usr/bin/X11/,${X11BASE}/,g" ${WRKSRC}/options.h
	@${REINPLACE_CMD} -e "s,sys/dir.h,dirent.h," ${WRKSRC}/*.[ch]
	@${REINPLACE_CMD} -e "s,make clean,\$${MAKE} clean," \
				${WRKSRC}/libtomcrypt/Makefile.in
	@${SED} -e 's:__PREFIX__:${PREFIX}:g' \
		${FILESDIR}/dropbear.sh > ${WRKSRC}/dropbear.sh

post-install:
	@${MKDIR} ${PREFIX}/etc/dropbear
	@${ECHO_MSG} ""
.if defined(WANT_STATIC)
	@${ECHO_MSG} " WARNING: deprecated option WANT_STATIC used, use 'make config' instead"
	@${ECHO_MSG} ""
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/dropbear.sh ${PREFIX}/etc/rc.d/dropbear.sh.sample
	@${ECHO_MSG} " Now you have to create your SSH host key."
	@${ECHO_MSG} ""
	@${ECHO_MSG} " To create RSA key:"
	@${ECHO_MSG} " ${PREFIX}/bin/dropbearkey -t rsa -f ${PREFIX}/etc/dropbear/dropbear_rsa_host_key"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " For more details, run ${PREFIX}/bin/dropbearkey -h"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
