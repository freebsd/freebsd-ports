# Created by: Nick Barkas <snb@threerings.net>
# $FreeBSD$

PORTNAME=	openvpn-auth-ldap
PORTVERSION=	2.0.4.0.s1379
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	LOCAL/mandree # figure out proper GitHub commit and use that.
# https://github.com/threerings/openvpn-auth-ldap/
DISTNAME=	auth-ldap-${PORTVERSION}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	LDAP authentication plugin for OpenVPN

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	re2c:devel/re2c \
		check>=0:devel/check \
		${LOCALBASE}/include/openvpn-plugin.h:security/openvpn

USES=		autoreconf objc tar:xz

GNU_CONFIGURE=	yes
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=	--with-openldap=${LOCALBASE} \
			--with-openvpn=${LOCALBASE}/include \
			--with-objc-runtime=GNU

PORTDOCS=	README
PORTEXAMPLES=	auth-ldap.conf
PLIST_FILES=	lib/openvpn-auth-ldap.so
OBJCFLAGS+=	-L${LOCALBASE}/lib -I${LOCALBASE}/include -fPIC
CFLAGS+=	-fPIC
MAKE_JOBS_UNSAFE=yes # work around missing deps in src/Makefile[.in]

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

CONFIGURE_ENV+=	OBJC="${CC}"

post-patch:
	${REINPLACE_CMD} 's|-export-dynamic|-Wl,-export-dynamic|' ${WRKSRC}/configure.ac

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/openvpn-auth-ldap.so
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/auth-ldap.conf ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>

CC+=		${DEBUG_FLAGS}

# this is a local target to build a tarball from SVN
# and another target to upload it
# Note that googlecode.com is gone. Apparently someone exported the code
# to Github, but aside from a README that got converted to Markdown
# syntax, there hadn't been changes as of 2016-12-07.
# https://github.com/threerings/openvpn-auth-ldap/
build-tarball: ${DISTFILES}
${DISTFILES}:
	${RM} -r ${WRKSRC}
	svn export -r${PORTVERSION:E:C/^s//} \
	    http://openvpn-auth-ldap.googlecode.com/svn/trunk/ ${WRKSRC}
	tar -C ${WRKSRC}/.. -cvf - ${WRKSRC:T} | ${XZ_CMD} -vvc >${DISTFILES} || \
	    { ${RM} ${DISTFILES} ; exit 1 ; }

upload-tarball: build-tarball
	scp ${DISTFILES} freefall.freebsd.org:public_distfiles/

.include <bsd.port.post.mk>
