# New ports collection makefile for:	exim
# Version required:	3.10
# Date created:		23 June 1996
# Whom:			markm@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	exim-3.12
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/ \
		ftp://ftp.quite.net/pub/exim/ \
		http://www.exim.org/ftp/ \
		ftp://ftp.is.co.za/networking/mail/transport/exim/
DISTFILES=	exim-3.12.tar.gz exim-texinfo-3.10.tar.gz

MAINTAINER=	sheldonh@FreeBSD.org

# If USE_XLIB is defined, the eximon monitor, which requires X, will be
# built. Comment it out unless you have or want XFree86 installed!
USE_XLIB=	YES

USE_PERL5=	YES

MAKE_ENV+=	OSTYPE=${OPSYS} ARCHTYPE=${MACHINE_ARCH}

# Uncomment the USE_LDAP and USE_MYSQL definitions to link against libldap
# and libmysqlclient respectively:
#USE_LDAP=	YES
#USE_MYSQL=	YES

# If USE_LDAP==YES then LDAP_LIB_TYPE should be one of UMICHIGAN, NETSCAPE or
# SOLARIS7:
LDAP_LIB_TYPE=	UMICHIGAN

# You should not need to fiddle with anything below this point.

SEDLIST=	-e 's,XX_PREFIX_XX,${PREFIX},' \
		-e 's,XX_BINOWN_XX,${BINOWN},'
.if !defined(USE_XLIB) || ${USE_XLIB} != YES
SEDLIST+=	-e 's/^EXIM_MONITOR/\#EXIM_MONITOR/'
.endif

.if defined(USE_LDAP) && ${USE_LDAP} == YES
SEDLIST+=	-e 's,XX_LDAP_LIBS_XX,-L${PREFIX}/lib -lber -lldap,' \
		-e 's,XX_LDAP_INCLUDE_XX,-I${PREFIX}/include,' \
		-e 's,XX_LDAP_TYPE_XX,${LDAP_LIB_TYPE},'
.else
SEDLIST+=	-e 's,XX_LDAP_[^ ]*_XX,,' \
		-e 's,^LDAP_LIB_TYPE,\#LDAP_LIB_TYPE,'
.endif

.if defined(USE_MYSQL) && ${USE_MYSQL} == YES
SEDLIST+=	-e 's,XX_MYSQL_LIBS_XX,-L${PREFIX}/lib/mysql -lmysqlclient,' \
		-e 's,XX_MYSQL_INCLUDE_XX,-I${PREFIX}/include/mysql,'
.else
SEDLIST+=	-e 's,XX_MYSQL_[^ ]*_XX,,'
.endif

.if ( !defined(USE_LDAP) || ${USE_LDAP} != YES ) && \
    ( !defined(USE_MYSQL) || ${USE_MYSQL} != YES )
SEDLIST+=	-e 's/^LOOKUP_LIBS/\#LOOKUP_LIBS/' \
		-e 's/^LOOKUP_INCLUDE/\#LOOKUP_INCLUDE/'
.endif

do-configure:
	${MKDIR} ${WRKSRC}/Local
	${SED} ${SEDLIST} < ${FILESDIR}/Makefile > ${WRKSRC}/Local/Makefile
	${SED} ${SEDLIST} < ${FILESDIR}/configure.default \
	    > ${WRKSRC}/src/configure.default
	${CP} ${FILESDIR}/eximon.conf ${WRKSRC}/Local
	cd ${WRKSRC}/doc && \
	for i in ../../exim-texinfo-3.10/doc/* ; do \
		${LN} -sf $$i ; \
	done

post-build:
	${INSTALL_SCRIPT} ${FILESDIR}/exim.sh \
		${WRKSRC}/build-${OPSYS}-${MACHINE_ARCH}
	${TOUCH} ${WRKSRC}/build-${OPSYS}-${MACHINE_ARCH}/eximon.bin
	${TOUCH} ${WRKSRC}/build-${OPSYS}-${MACHINE_ARCH}/eximon

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
