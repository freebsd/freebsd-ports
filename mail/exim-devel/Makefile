# New ports collection makefile for:	exim
# Version required:	3.13
# Date created:		23 June 1996
# Whom:			markm@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	exim-3.13
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cus.cam.ac.uk/pub/software/programs/exim/ \
		http://www.exim.org/ftp/ \
		ftp://ftp.is.co.za/networking/mail/transport/exim/
DISTFILES=	exim-3.13.tar.gz exim-texinfo-3.10.tar.gz

MAINTAINER=	sheldonh@FreeBSD.org

# If USE_XLIB is defined, the eximon monitor, which requires X, will be
# built. Comment it out unless you have or want XFree86 installed!
USE_XLIB=	YES

USE_PERL5=	YES

MAKE_ENV+=	OSTYPE=${OPSYS} ARCHTYPE=${MACHINE_ARCH}

# Uncomment the USE_LDAP, USE_MYSQL and USE_PAM definitions to link against
# libldap, libmysqlclient and libpam respectively.  The libpam linkage is
# required for SMTP AUTH support.
#USE_LDAP=	YES
#USE_MYSQL=	YES
#USE_PAM=	YES

# If USE_LDAP==YES then LDAP_LIB_TYPE should be one of UMICHIGAN, NETSCAPE or
# SOLARIS7:
LDAP_LIB_TYPE=	UMICHIGAN

# If USE_PAM==YES then one or more of USE_CRAM_MD5 and USE_PLAINTEXT
# must be left uncommented.
PAM_CRAM_MD5=	YES
PAM_PLAINTEXT=	YES

# Uncomment to compile support for non-standard mailbox formats.
#USE_MAILDIR=	YES
#USE_MAILSTORE=	YES
#USE_MBX=	YES

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

.if ( !defined(USE_PAM) || ${USE_PAM} != YES )
SEDLIST+=	-e 's/^SUPPORT_PAM/\#SUPPORT_PAM/' \
		-e 's/^PAM_LIBS/\#PAM_LIBS/'
.endif

.if ( !defined(USE_PAM) || ${USE_PAM} != YES ) || \
    ( !defined(PAM_CRAM_MD5) || ${PAM_CRAM_MD5} != YES )
SEDLIST+=	-e 's/^AUTH_CRAM_MD5/\#AUTH_CRAM_MD5/'
.endif

.if ( !defined(USE_PAM) || ${USE_PAM} != YES ) || \
    ( !defined(PAM_PLAINTEXT) || ${PAM_PLAINTEXT} != YES )
SEDLIST+=	-e 's/^AUTH_PLAINTEXT/\#AUTH_PLAINTEXT/'
.endif

.if defined(USE_MAILDIR) && ${USE_MAILDIR} == YES
SEDLIST+=	-e 's/^\# SUPPORT_MAILDIR/SUPPORT_MAILDIR/'
.endif

.if defined(USE_MAILSTORE) && ${USE_MAILSTORE} == YES
SEDLIST+=	-e 's/^\# SUPPORT_MAILSTORE/SUPPORT_MAILSTORE/'
.endif

.if defined(USE_MBX) && ${USE_MBX} == YES
SEDLIST+=	-e 's/^\# SUPPORT_MBX/SUPPORT_MBX/'
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

.include <bsd.port.mk>
