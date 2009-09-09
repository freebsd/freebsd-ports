# New ports collection makefile for:	samesame
# Date created:		14 April 2009
# Whom:			Alex de Kruijff
#
# $FreeBSD$

PORTNAME=	samesame
PORTVERSION=	1.5
CATEGORIES=	sysutils
MASTER_SITES=	http://samesame.kruijff.org/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn

MAINTAINER=	samesame@akruijff.dds.nl
COMMENT=	Find identical files and optionally link them together

CONFLICTS=	samefile-[0-9]*

MAN1=	samesame.1 samearchive.1 samearchive-lite.1 samefile.1 sameln.1 \
	samecp.1 samemv.1 samerm.1
MANCOMPRESSED=	no

PLIST_FILES=	bin/samearchive		bin/samefile 	bin/samecp \
		bin/samearchive-lite	bin/sameln 	bin/samemv \
		etc/rc.d/samesame.sh	bin/samerm

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir="${MANPREFIX}/man" --prefix="${PREFIX}" \
		--includedir="${LOCALBASE}/include" --libdir="${LOCALBASE}/lib"
USE_BZIP2=	yes

OPTIONS=	DEBUG "Enables debugging support" Off \
		DISK_STORAGE "Allows temporarily storage paths on disk" On \
		LOGIC "Determine results by using logic when posible" On \
		TEST "Run quality assurance test" Off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_DISK_STORAGE)
CONFIGURE_ARGS+=	--enable-disk-storage
.endif

.if defined(WITHOUT_LOGIC)
CONFIGURE_ARGS+=	--disable-logic
.endif

regression-test: build
	@cd ${WRKSRC}; ${MAKE} check

post-build:
.if defined(WITH_TEST)
	@cd ${WRKSRC}; ${MAKE} check
.endif

post-install:
.if defined(WITHOUT_DEBUG)
	${STRIP_CMD} ${PREFIX}/bin/samefile
	${STRIP_CMD} ${PREFIX}/bin/samearchive
	${STRIP_CMD} ${PREFIX}/bin/samearchive-lite
	${STRIP_CMD} ${PREFIX}/bin/samecp
	${STRIP_CMD} ${PREFIX}/bin/sameln
	${STRIP_CMD} ${PREFIX}/bin/samemv
	${STRIP_CMD} ${PREFIX}/bin/samerm
.endif

	${INSTALL_SCRIPT} ${FILESDIR}/samesame.sh ${PREFIX}/etc/rc.d/
	@${ECHO}
	@${CAT} pkg-message
	@${ECHO}

.include <bsd.port.post.mk>
