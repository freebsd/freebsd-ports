# New ports collection makefile for:	dropbear
# Date created:				20 August 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	dropbear
PORTVERSION=	0.38
CATEGORIES=	security ipv6
MASTER_SITES=	http://matt.ucc.asn.au/dropbear/releases/

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	An SSH 2 server, designed to be usable in small memory environments

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_REINPLACE=	YES

.if defined(IS_STATIC)
CONFIGURE_ENV=	LDFLAGS=-static
.endif

MAKE_ENV+=	INSTALL="${INSTALL}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"
post-configure:
	@${REINPLACE_CMD} -e "s,/etc/,${PREFIX}/etc/,g" ${WRKSRC}/options.h
	@${REINPLACE_CMD} -e "s,/usr/bin/X11/,${X11BASE}/,g" ${WRKSRC}/options.h
	@${REINPLACE_CMD} -e "s,^typedef int socklen_t,//typedef int socklen_t," \
		${WRKSRC}/includes.h
	${SED} -e 's:__PREFIX__:${PREFIX}:g' \
		${FILESDIR}/dropbear.sh > ${WRKSRC}/dropbear.sh

post-install:
	@${MKDIR} ${PREFIX}/etc/dropbear
.if !defined(NOPORTDOC)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/dropbear.sh ${PREFIX}/etc/rc.d/dropbear.sh.sample

.include <bsd.port.mk>
