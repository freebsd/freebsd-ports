# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pam_krb5
DISTVERSION=	2.4.9
CATEGORIES=	security
MASTER_SITES=	https://fedorahosted.org/released/${PORTNAME}/ \
		http://mirrors.rit.edu/zi/
PKGNAMESUFFIX=	-rh

MAINTAINER=	zi@FreeBSD.org
COMMENT=	The Red Hat Pluggable Authentication Module for Kerberos 5

LICENSE=	LGPL21 BSD
LICENSE_COMB=	dual

CONFLICTS=	pam_krb5-4.*

USES=		iconv
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=${ICONV_CONFIGURE_ARG} --without-afs \
		--with-libintl-prefix=${LOCALBASE} --with-krb4=no \
		--without-keyutils
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
LDFLAGS+=	-lintl
USES+=		gettext
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=--disable-nls
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/security|libdir)|g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|/lib64/security|${LOCALBASE}/lib|g' \
		${WRKSRC}/src/*.8
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/tests/tools/Makefile.in
	@${REINPLACE_CMD} -e 's|PAM_BAD_ITEM|PAM_SYMBOL_ERR|g' ${WRKSRC}/src/conv.c
	@${REINPLACE_CMD} -e 's|PAM_AUTHTOK_RECOVER_ERR|PAM_AUTHTOK_RECOVERY_ERR|g' \
		${WRKSRC}/src/password.c

.include <bsd.port.mk>
