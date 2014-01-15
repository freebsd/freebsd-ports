# Created by: Michael Joyner <mjoyner@hq.dyns.cx>
# $FreeBSD$

PORTNAME=	yptransitd
PORTVERSION=	0.5
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Replacement for nss_ldap

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		bison
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldap-prefix=${LOCALBASE}
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	%%ETCDIR%%/ldap.conf %%ETCDIR%%/modules/ldap.so \
		%%ETCDIR%%/yptransitd.conf sbin/yptransitd
PLIST_DIRS=	%%ETCDIR%%/modules %%ETCDIR%%

post-patch:
	@${REINPLACE_CMD} -e 's, $$(CONFDIR), $${DESTDIR}$$(CONFDIR),' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's,=gcc,=@CC@,' \
		${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} -e 's,-O2 -g,@CFLAGS@, ; \
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
