PORTNAME=	yptransitd
PORTVERSION=	0.5
PORTREVISION=	8
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Replacement for nss_ldap
WWW=		https://yptransitd.sourceforge.net/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ldap bison
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldap-prefix=${LOCALBASE}

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	%%ETCDIR%%/ldap.conf %%ETCDIR%%/modules/ldap.so \
		%%ETCDIR%%/yptransitd.conf sbin/yptransitd

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e 's, \($$([A-Z]*DIR)\), $${DESTDIR}\1,g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's,=gcc,=@CC@,' \
		${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} -e 's,-O2 -g,@CFLAGS@ -fcommon, ; \
		 s, $${BINDIR}, $${DESTDIR}$${BINDIR},' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -E 's,^([[:blank:]]+)\([^\)]+\) ,\1,' \
		${WRKSRC}/src/modules.c
	@${REINPLACE_CMD} -e 's,-O2 -g,@CFLAGS@, ; \
		 s, $$(CONFDIR), $${DESTDIR}$$(CONFDIR),' \
		${WRKSRC}/src/modules/ldap/Makefile.in
	@${REINPLACE_CMD} -e 's,(void \*) ,,g' \
		${WRKSRC}/src/modules/ldap/cache.c

pre-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/modules

.include <bsd.port.mk>
