# New ports collection makefile for:    libesmtp
# Date created:         Sun Feb 21 2001
# Whom:                 tobez@tobez.org
#
# $FreeBSD$

PORTNAME=	libesmtp
PORTVERSION=	1.0.3
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.stafford.uklinux.net/libesmtp/ \
		http://www.tobez.org/download/port-mirrors/mail/libesmtp/ \
		http://www.borgsdemons.com/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}r1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for posting electronic mail

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_INC_LIBTOOL_VER=15
USE_PERL5_BUILD=yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

# require-all-recipients (implied by enable-all) is required for Balsa
CONFIGURE_ARGS=	--enable-all --disable-isoc

DOCS=		AUTHORS ChangeLog NEWS Notes README TODO
EXAMPLES=	examples/*

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
