# New ports collection makefile for: pidgin-sipe
# Date created:  7 May 2009
# Whom:          John Prather
#
# $FreeBSD$
#

PORTNAME=	pidgin-sipe
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	SFP/sipe/sipe/${DISTNAME}

MAINTAINER=	john.c.prather@gmail.com
COMMENT=	A plugin for Pidgin to provide LCS/OCS connectivity

LIB_DEPENDS=	purple.6:${PORTSDIR}/net-im/libpurple
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_LDCONFIG=	${PREFIX}/lib/pidgin
USE_GETTEXT=	yes

BROKEN=	needs update for libpurple-2.6.1

CFLAGS+=	"-I/${LOCALBASE}/include"
LIBS+=		"-L/${LOCALBASE}/lib"

CONFIGURE_ENV+=	LIBS="${LIBS}" \
		COM_ERR_CFLAGS="-I/usr/include" \
		COM_ERR_LIBS="-L/usr/lib -lcom_err"

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS ChangeLog COPYING HACKING INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
