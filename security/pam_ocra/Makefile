PORTNAME=	pam_ocra
DISTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	sg2342@googlemail.com
COMMENT=	RFC6287 (OCRA) PAM module
WWW=		https://github.com/sg2342/pam_ocra

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ssl uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	sg2342

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

MAKE_ARGS=	MANDIR="${PREFIX}/share/man/man"

PLIST_FILES=	lib/pam_ocra.so \
		lib/pam_ocra.so.0 \
		sbin/ocra_tool \
		share/man/man8/pam_ocra.8.gz \
		share/man/man8/ocra_tool.8.gz

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=cast-align
.endif

.include <bsd.port.mk>
