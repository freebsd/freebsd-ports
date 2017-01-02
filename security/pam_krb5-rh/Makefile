# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pam_krb5
DISTVERSION=	2.4.13
CATEGORIES=	security
MASTER_SITES=	https://fedorahosted.org/released/${PORTNAME}/ \
		http://mirrors.rit.edu/zi/
PKGNAMESUFFIX=	-rh

MAINTAINER=	zi@FreeBSD.org
COMMENT=	The Red Hat Pluggable Authentication Module for Kerberos 5

LICENSE=	LGPL21 BSD3CLAUSE
LICENSE_COMB=	dual

CONFLICTS=	pam_krb5-4.*

USES=		iconv libtool ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-afs --without-keyutils --without-krb4
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_LIBS=	-lintl
NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/security|libdir)|g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|/lib64/security|${LOCALBASE}/lib|g' \
		${WRKSRC}/src/*.8
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/tests/tools/Makefile.in
	@${REINPLACE_CMD} -e 's|PAM_BAD_ITEM|PAM_SYMBOL_ERR|g' ${WRKSRC}/src/conv.c
	@${REINPLACE_CMD} -e 's|PAM_AUTHTOK_RECOVER_ERR|PAM_AUTHTOK_RECOVERY_ERR|g' \
		${WRKSRC}/src/password.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pam_krb5.so

.include <bsd.port.mk>
