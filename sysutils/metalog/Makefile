# New ports collection makefile for:	metalog
# Date Created:				27 Aug 2002
# Whom:					Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	metalog
PORTVERSION=	0.7
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Modern syslogd replacement with PCRE support

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

# Needed for metalog's configure to find installed devel/pcre port
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN8=		metalog.8
DOCS=		AUTHORS NEWS README

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/metalog.conf ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
