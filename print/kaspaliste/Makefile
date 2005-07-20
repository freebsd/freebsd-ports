# New ports collection makefile for:	kaspaliste
# Date created:				16 December 2003
# Whom:					jaapb
#
# $FreeBSD$
#

PORTNAME=		kaspaliste
PORTVERSION=		0.96
PORTREVISION=		2
CATEGORIES=		print kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kaspaliste

MAINTAINER=		jaapb@kerguelen.org
COMMENT=		Bibliography tool for KDE/Postgres/BibTeX

USE_PGSQL=		yes
USE_KDEBASE_VER=	3
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}	\
			--with-pg-includes=${LOCALBASE}/include \
			--with-pg-libs=${LOCALBASE}/lib

PKGMESSAGE=		${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600031
BROKEN=			"Does not compile on FreeBSD >= 6.0"
.endif

pre-configure:
	@${RM} ${WRKSRC}/config.cache

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/create.tables.sql ${DATADIR}
	@${SED} -e "s|%%DATADIR%%|${DATADIR}|" < ${FILESDIR}/pkg-message.in	\
		> ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
