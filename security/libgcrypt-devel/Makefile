# New ports collection Makefile for:	libgcrypt
# Date created:				July 17 2002
# Whom:					Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libgcrypt
PORTVERSION=	1.1.91
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	alpha/libgcrypt
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}.sig

MAINTAINER=	arved@FreeBSD.org
COMMENT=	"General purpose crypto library based on code used in GnuPG"

LIB_DEPENDS=	gpg-error.1:${PORTSDIR}/security/libgpg-error \
		pth.20:${PORTSDIR}/devel/pth

CONFLICTS=	libgcrypt-1.1*
USE_REINPLACE=	yes
USE_PERL5=	yes
USE_GNOME=	lthack
USE_LIBTOOL=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split" \
		CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include/pth" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib/pth"
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

INFO=	gcrypt

.include <bsd.port.pre.mk>

pre-extract:
.if exists(${PREFIX}/bin/gpg)
	@${MKDIR} ${WRKDIR}
	@${ECHO_CMD} "===> Verifying GnuPG Signature."
	-${PREFIX}/bin/gpg --no-default-keyring --keyring ${WRKDIR}/keyring \
		--keyserver pgp.mit.edu --recv-key 57548DCD
	cd ${DISTDIR}; ${PREFIX}/bin/gpg --keyring ${WRKDIR}/keyring --verify \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}.sig \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
.else
	@${ECHO_CMD} "===> GnuPG not installed. Signature can not be verified"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|" \
		${WRKSRC}/ltmain.sh

pre-configure:
	@${RM} -f ${WRKSRC}/doc/gcrypt.info*

.include <bsd.port.post.mk>
