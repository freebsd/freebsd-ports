# Created by: Lars Eggert <larse@isi.edu>
# $FreeBSD$

PORTNAME=	mod_perl
PORTVERSION=	2.0.8
PORTREVISION=	2
PORTEPOCH=	3
CATEGORIES=	www perl5
MASTER_SITES=	APACHE/perl
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	ohauer

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Embeds a Perl interpreter in the Apache2 server

LICENSE=	APACHE20

BUILD_DEPENDS=	p5-BSD-Resource>=0:${PORTSDIR}/devel/p5-BSD-Resource
RUN_DEPENDS:=	${BUILD_DEPENDS}

SUB_FILES=	pkg-message
SUB_LIST=	APACHEMODDIR=${APACHEMODDIR}
USE_APACHE=	22+
USES=		gmake perl5
USE_PERL5=	configure
USE_CSTD=	gnu89

.include <bsd.port.pre.mk>

# In case apache22 is in use and you want to test
# the new mod_perl, change '> 22' to '>= 22'
.if ${APACHE_VERSION} > 22
# patch shaped against upstream mod_perl
# Last Changed Rev: 1602105
PATCHREV=	1618150
PATCHFILES+= 	${PORTNAME}-${PORTVERSION}-r${PATCHREV}.diff.gz
PLIST_SUB+=	AP24=""
PMSED=		's/%AP24%//'
NO_PACKAGE=	yes
.else
PLIST_SUB+=	AP24="@comment "
PMSED=		'/%AP24%/d'
.endif

# Provider is build iff apache24 is in use
.if ${APACHE_VERSION:M22}
PLIST_SUB+=	AP22="@comment "
.else
PLIST_SUB+=	AP22=""
.endif

# Using apxs in this way is problematic if apache2 is installed under a
# different PREFIX than mod_perl2, because the mod_perl2 installation will
# use paths returned by apxs to install some components. Fixes welcome.
CONFIGURE_ARGS=	PREFIX=${PREFIX} MP_APXS=${APXS} MP_APR_CONFIG=${LOCALBASE}/bin/apr-1-config

.if exists(${LOCALBASE}/include/apr-1/apr.h)
APR_H=		${LOCALBASE}/include/apr-1/apr.h
APR_MAJ_V!=	${ECHO_CMD} `${LOCALBASE}/bin/apr-1-config --version | ${SED} -e 's,\..*,,'`
.endif

.if defined(APR_H)
APR_HAS_THREADS!=	${ECHO_CMD} `${GREP} -c 'APR_HAS_THREADS *1' ${APR_H}`
.else
APR_HAS_THREADS=	0
.endif

.if ${APR_HAS_THREADS} == 1
PLIST_SUB+=	THREADMUTEX=""
PLIST_SUB+=	THREADRWLOCK=""
.else
PLIST_SUB+=	THREADMUTEX="@comment "
PLIST_SUB+=	THREADRWLOCK="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's/APR_INLINE//g' \
		${PATCH_WRKSRC}/src/modules/perl/modperl_common_util.h
	${REINPLACE_CMD} -e "s|/usr/local/apache/bin/apxs|${APXS}|" \
		-e "s|'bin', 'apxs'|'sbin', 'apxs'|" \
		${WRKSRC}/lib/Apache2/Build.pm

pre-configure:
	${FIND} ${WRKSRC} -type f \( -name \*.bak -o -name \*.orig \) -delete

post-configure:
	${REINPLACE_CMD} -e 's/-pthread -Wl,-E//g' \
		${PATCH_WRKSRC}/xs/APR/APR/Makefile

post-install:
# adjust pkg-message
	${REINPLACE_CMD} -e ${PMSED} ${WRKDIR}/pkg-message
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEINCLUDEDIR}/modules/perl
	${INSTALL_DATA} ${WRKSRC}/src/modules/perl/*.h \
		${STAGEDIR}${PREFIX}/${APACHEINCLUDEDIR}/modules/perl
	${INSTALL_DATA} ${WRKSRC}/xs/*.h ${STAGEDIR}${PREFIX}/${APACHEINCLUDEDIR}
	${INSTALL_DATA} ${WRKSRC}/xs/APR/PerlIO/*.h ${STAGEDIR}${PREFIX}/${APACHEINCLUDEDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/modules/perl/mod_perl.so \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_perl.so

	-for f in `${FIND} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto -name \*.so` ; do \
		${CHMOD} u+w $${f}; \
		${STRIP_CMD} $${f}; \
		${CHMOD} u-w $${f}; \
	done;

test:	build
	-@(${MAKE} test -C ${WRKSRC})

.include <bsd.port.post.mk>
