PORTNAME=	openca-ocspd
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.3
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	bruno@ruomad.net
COMMENT=	OpenCA OCSP responder
WWW=		https://www.openca.org/projects/ocspd

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=	arm64

LIB_DEPENDS=	libpki.so:security/libpki

USES=		autoreconf gnome libtool shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	openca
USE_GNOME=	libxml2
# Add a rc script to start the OCSP daemon
USE_RC_SUBR=	ocspd

SHEBANG_FILES=	etc/ocspd.in scripts/ocspd-genreq.sh.in

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libpki-prefix=${PREFIX}

# Rename installed configuration files to samples
post-stage:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/openca-ocspd/etc; \
	${MKDIR} ${STAGEDIR}${PREFIX}/share/openca-ocspd/etc/ocspd; \
	${MKDIR} ${STAGEDIR}${PREFIX}/share/openca-ocspd/etc/ocspd/ca.d; \
	${MKDIR} ${STAGEDIR}${PREFIX}/share/openca-ocspd/etc/ocspd/pki; \
	${MKDIR} ${STAGEDIR}${PREFIX}/share/openca-ocspd/etc/ocspd/pki/token.d; \
	cd ${STAGEDIR}${PREFIX}/etc/ocspd/pki; \
	for f in $$(find * -type f); do \
		${MV} ${STAGEDIR}${PREFIX}/etc/ocspd/pki/$$f ${STAGEDIR}${PREFIX}/share/openca-ocspd/etc/ocspd/pki/$$f.sample; \
	done; \
	cd ${STAGEDIR}${PREFIX}/etc/ocspd/ca.d; \
	for f in $$(find * -type f); do \
		${MV} ${STAGEDIR}${PREFIX}/etc/ocspd/ca.d/$$f ${STAGEDIR}${PREFIX}/share/openca-ocspd/etc/ocspd/ca.d/$$f.sample; \
	done; \
	for f in $$(find ${STAGEDIR}${PREFIX}/etc/ocspd -type f); do \
		${MV} $$f $$f.sample; \
	done; \
	${RM} ${STAGEDIR}${PREFIX}/bin/test.sh; \
	${RM} ${STAGEDIR}${PREFIX}/etc/init.d/ocspd; \
	${RMDIR} ${STAGEDIR}${PREFIX}/etc/init.d
	${RMDIR} ${STAGEDIR}${PREFIX}/var/run
	${RMDIR} ${STAGEDIR}${PREFIX}/var

.include <bsd.port.mk>
