# New ports collection makefile for:	exim
# Date created:		23 June 1996
# Whom:			markm@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	exim
PORTVERSION=	3.22
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/ \
		http://www.exim.org/ftp/ \
		ftp://ftp.is.co.za/networking/mail/transport/exim/
DISTFILES=	exim-3.22.tar.gz exim-texinfo-3.20.tar.gz

MAINTAINER=	sheldonh@FreeBSD.org

# If WITHOUT_X11 is not defined, the eximon monitor, which requires X, will
# be built. Comment it out unless you have or want XFree86 installed!
.if !defined(WITHOUT_X11)
USE_XLIB=	yes
.endif

USE_PERL5=	yes

MAKE_ENV+=	OSTYPE=${OPSYS} ARCHTYPE=${MACHINE_ARCH}

# Uncomment the WITH_LDAP, WITH_MYSQL, WITH_PAM and WITH_PGSQL definitions
# to link against libmysqlclient, libpam and libpq respectively.
# The libpam linkage is required for SMTP AUTH support.
#WITH_LDAP=	yes
#WITH_MYSQL=	yes
#WITH_PAM=	yes
#WITH_PGSQL=	yes

# Link against OpenSSL in the base system for STARTTLS support.
#WITH_TLS=	yes

# Enable the embedded Perl interpreter, allowing Perl subroutines to be
# called during string expansion.
WITH_PERL=	yes

# If WITH_PAM is defined then one or more of PAM_CRAM_MD5 and PAM_PLAINTEXT
# must be left uncommented.
PAM_CRAM_MD5=	yes
PAM_PLAINTEXT=	yes

# If WITH_LDAP is defined, LDAP_LIB_TYPE must be one of UMICHIGAN,
# NETSCAPE or SOLARIS7.
LDAP_LIB_TYPE=UMICHIGAN

# Uncomment to compile support for non-standard mailbox formats.
#WITH_MAILDIR=	yes
#WITH_MAILSTORE=	yes
#WITH_MBX=	yes

# You should not need to fiddle with anything below this point.

SEDLIST=	-e 's,XX_PREFIX_XX,${PREFIX},' \
		-e 's,XX_BINOWN_XX,${BINOWN},'
.if !defined(USE_XLIB)
SEDLIST+=	-e 's,^EXIM_MONITOR,\#EXIM_MONITOR,'
.endif

.if defined(WITH_TLS)
SEDLIST+=	-e 's,XX_TLS_LIBS_XX,-lssl -lcrypto,' \
		-e 's,^\# SUPPORT_TLS,SUPPORT_TLS,'
.else
SEDLIST+=	-e 's,^TLS_LIBS,\#TLS_LIBS,'
.endif

.if !defined(WITH_PERL)
SEDLIST+=	-e 's,^EXIM_PERL,\#EXIM_PERL,'
.endif

.if defined(WITH_LDAP)
LIB_DEPENDS+=	lber.1:${PORTSDIR}/net/openldap
SEDLIST+=	-e 's,XX_LDAP_LIBS_XX,-L${PREFIX}/lib -llber -lldap,' \
		-e 's,XX_LDAP_INCLUDE_XX,-I${PREFIX}/include,' \
		-e 's,XX_LDAP_TYPE_XX,${LDAP_LIB_TYPE},' \
		-e 's,^\# LOOKUP_LDAP,LOOKUP_LDAP,'
.else
SEDLIST+=	-e 's,XX_LDAP_[^ ]*_XX,,' \
		-e 's,^LDAP_LIB_TYPE,\#LDAP_LIB_TYPE,'
.endif

.if defined(WITH_MYSQL)
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
SEDLIST+=	-e 's,XX_MYSQL_LIBS_XX,-L${PREFIX}/lib/mysql -lmysqlclient,' \
		-e 's,XX_MYSQL_INCLUDE_XX,-I${PREFIX}/include/mysql,' \
		-e 's,^\# LOOKUP_MYSQL,LOOKUP_MYSQL,'
.else
SEDLIST+=	-e 's,XX_MYSQL_[^ ]*_XX,,'
.endif

.if defined(WITH_PAM)
SEDLIST+=	-e 's,XX_PAM_LIBS_XX,-lpam,'
.else
SEDLIST+=	-e 's,XX_PAM_LIBS_XX,,' \
		-e 's,^SUPPORT_PAM,\#SUPPORT_PAM,' 
.endif

.if !defined(WITH_PAM) || !defined(PAM_CRAM_MD5)
SEDLIST+=	-e 's,^AUTH_CRAM_MD5,\#AUTH_CRAM_MD5,'
.endif

.if !defined(WITH_PAM) || !defined(PAM_PLAINTEXT)
SEDLIST+=	-e 's,^AUTH_PLAINTEXT,\#AUTH_PLAINTEXT,'
.endif

.if defined(WITH_PGSQL)
LIB_DEPENDS+=	pq.2:${PORTSDIR}/databases/postgresql7
SEDLIST+=	-e 's,XX_PGSQL_LIBS_XX,-L${PREFIX}/pgsql/lib -lpq,' \
		-e 's,XX_PGSQL_INCLUDE_XX,-I${PREFIX}/pgsql/include,' \
		-e 's,^\# LOOKUP_PGSQL,LOOKUP_PGSQL,'
.else
SEDLIST+=	-e 's,XX_PGSQL_[^ ]*_XX,,'
.endif

.if !defined(WITH_PGSQL) && !defined(WITH_MYSQL) && !defined(WITH_LDAP)
SEDLIST+=	-e 's,^LOOKUP_LIBS,\#LOOKUP_LIBS,' \
		-e 's,^LOOKUP_INCLUDE,\#LOOKUP_INCLUDE,'
.endif

.if defined(WITH_MAILDIR)
SEDLIST+=	-e 's,^\# SUPPORT_MAILDIR,SUPPORT_MAILDIR,'
.endif

.if defined(WITH_MAILSTORE)
SEDLIST+=	-e 's,^\# SUPPORT_MAILSTORE,SUPPORT_MAILSTORE,'
.endif

.if defined(WITH_MBX)
SEDLIST+=	-e 's,^\# SUPPORT_MBX,SUPPORT_MBX,'
.endif

do-configure:
	${MKDIR} ${WRKSRC}/Local
	${SED} ${SEDLIST} < ${FILESDIR}/Makefile > ${WRKSRC}/Local/Makefile
	${SED} ${SEDLIST} < ${FILESDIR}/configure.default \
	    > ${WRKSRC}/src/configure.default
	${CP} ${FILESDIR}/eximon.conf ${WRKSRC}/Local
	cd ${WRKSRC}/doc && \
	for i in ../../exim-texinfo-3.20/doc/* ; do \
		${LN} -sf $$i ; \
	done

post-build:
	${INSTALL_SCRIPT} ${FILESDIR}/exim.sh \
		${WRKSRC}/build-${OPSYS}-${MACHINE_ARCH}
	${TOUCH} ${WRKSRC}/build-${OPSYS}-${MACHINE_ARCH}/eximon.bin
	${TOUCH} ${WRKSRC}/build-${OPSYS}-${MACHINE_ARCH}/eximon

.include <bsd.port.mk>
