# New ports collection makefile for:	tripwire 2.3.1
# Date created:		Tue Mar  6 06:57:58 PST 2001
# Whom:			Cy Schubert <Cy.Schubert@uumail.gov.bc.ca>
#
# $FreeBSD$
#

PORTNAME=	tripwire
PORTVERSION=	2.3.1.2
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.[0-9]*$/-&/:C/-\./-/}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	File system security and verification program

LATEST_LINK=	${PORTNAME}
MAN5=		twfiles.5 twconfig.5 twpolicy.5
MAN8=		siggen.8 tripwire.8 twadmin.8 twintro.8 twprint.8
NO_PACKAGE=	"requires local database to be built"
WRKSRC=		${WRKDIR}/${DISTNAME}
BUILD_WRKSRC=	${WRKSRC}/src
USE_GMAKE=	yes
ALL_TARGET=	release
MAKE_ARGS=	SYSPRE=${ARCH}-unknown-freebsd
IS_INTERACTIVE=	yes

# Tripwire config files are stored in TWCFG
TWCFG?=		/usr/local/etc/tripwire
# Tripwire policy files are stored in TWPOLICY.
TWPOLICY?=	${TWCFG}
# The Tripwire site key files are stored in TWSITEKEYDIR.
TWSITEKEYDIR?=	${TWPOLICY}
# The Tripwire local key files are stored in TWLOCALKEYDIR.
TWLOCALKEYDIR?=	${TWPOLICY}
# Tripwire database files are stored in TWDB.
TWDB?=		/var/db/tripwire
# Tripwire report files are stored in TWREPORT.
TWREPORT?=	${TWDB}/report
# This sets the default text editor for Tripwire.
TWEDITOR?=	/usr/bin/vi
# This sets the location of the twpol.txt file that is to be installed
TWPOL_TXT?=	${FILESDIR}/twpol.txt
# Other variables that are used:
TRIPWIRE_CLOBBER?=	NO
#	If TRIPWIRE_CLOBBER is set to YES, the install script clobbers
#	previously installed config files.

.include <bsd.port.pre.mk>

PLIST_SUB+=	TWCFG=${TWCFG} TWDB=${TWDB}

.if ${OSVERSION} > 501000
USE_GCC=	2.95
USE_REINPLACE=	YES
.endif

pre-configure:
	@ ${CP} ${TWPOL_TXT} ${WRKSRC}/policy/twpol.txt
	@ ${MV} ${WRKSRC}/src/core/stdcore.h ${WRKSRC}/src/core/stdcore.h.orig
	@ ${SED} 's%^# define CONFIG_FILE_ROOT	"/usr/local/etc/tripwire"%# define CONFIG_FILE_ROOT	"${TWCFG}"%' ${WRKSRC}/src/core/stdcore.h.orig > ${WRKSRC}/src/core/stdcore.h
	@ ${MV} ${WRKSRC}/man/man4/twconfig.4 ${WRKSRC}/man/man5/twconfig.5
	@ ${MV} ${WRKSRC}/man/man4/twpolicy.4 ${WRKSRC}/man/man5/twpolicy.5

.if ${OSVERSION} > 501000
post-extract:
	@ ${REINPLACE_CMD} -e "s|CC \= gcc|CC \= gcc295|g" ${WRKSRC}/src/STLport-4.0/src/gcc.mak
	@ ${REINPLACE_CMD} -e "s|CXX \= c\+\+|CXX \= g\+\+295|g" ${WRKSRC}/src/STLport-4.0/src/gcc.mak
	@ ${REINPLACE_CMD} -e "s|ln \-s \/usr\/include\/g\+\+ include|ln \-s ${PREFIX}\/lib\/gcc\-lib\/${ARCH}\-portbld\-freebsd${OSREL}\/2.95.3\/include include|g" ${WRKSRC}/src/STLport-4.0/STLport.mak
	@ ${REINPLACE_CMD} -e "s|CC \= cc|CC \= gcc295|g" ${WRKSRC}/src/make_include/i386-unknown-freebsd.inc
	@ ${REINPLACE_CMD} -e "s|CXX \= c\+\+|CXX \= g\+\+295|g" ${WRKSRC}/src/make_include/i386-unknown-freebsd.inc
	@ ${REINPLACE_CMD} -e "s|LINKFLAGS_R \= \-pthread|LINKFLAGS_R \+\= \-lpthread|g" ${WRKSRC}/src/make_include/i386-unknown-freebsd.inc
	@ ${REINPLACE_CMD} -e "s|LINKFLAGS_D \= \-pthread|LINKFLAGS_D \+\= \-lpthread|g" ${WRKSRC}/src/make_include/i386-unknown-freebsd.inc
	@ ${REINPLACE_CMD} -e "s|CC \= g\+\+|CC \= g\+\+295|g" ${WRKSRC}/src/cryptlib/i386-unknown-freebsd.mak
	@ ${REINPLACE_CMD} -e "s|malloc.h|stdlib.h|g" ${WRKSRC}/src/core/msystem.cpp
	@ ${REINPLACE_CMD} -e "s|malloc.h|stdlib.h|g" ${WRKSRC}/src/twparser/yylex.cpp
	@ ${REINPLACE_CMD} -e "s|malloc.h|stdlib.h|g" ${WRKSRC}/src/tripwire/tripwiremain.cpp
.endif
	
install-software:
	@ ${ECHO_CMD} TWPOLICY=${TWPOLICY} >> ${WRKSRC}/install/install.cfg
	@ ${ECHO_CMD} TWSITEKEYDIR=${TWSITEKEYDIR} >> ${WRKSRC}/install/install.cfg
	@ ${ECHO_CMD} TWLOCALKEYDIR=${TWLOCALKEYDIR} >> ${WRKSRC}/install/install.cfg
	@ ${ECHO_CMD} TWDB=${TWDB} >> ${WRKSRC}/install/install.cfg
	@ ${ECHO_CMD} TWREPORT=${TWREPORT} >> ${WRKSRC}/install/install.cfg
	@ ${ECHO_CMD} TWEDITOR=${TWEDITOR} >> ${WRKSRC}/install/install.cfg
	@ ${ECHO_CMD} TWPOL_TXT=${TWPOL_TXT} >> ${WRKSRC}/install/install.cfg
	@ cd ${WRKSRC} && ${LN} -sf install/install.cfg install/install.sh .
.if ( defined(TRIPWIRE_CLOBBER) && ${TRIPWIRE_CLOBBER} == "YES" ) || \
    ( defined(TRIPWIRE_CLOBBER) && ${TRIPWIRE_CLOBBER} == "yes" )
	@ cd ${WRKSRC} && PREFIX=${PREFIX} ./install.sh -f
.else
	@ cd ${WRKSRC} && PREFIX=${PREFIX} ./install.sh
.endif

create-database:
.ifndef NO_DB_BUILD
	@ ${MKDIR} -p ${TWCFG} ${TWPOLICY} ${TWSITEKEYDIR} ${TWLOCALKEYDIR} \
		${TWDB} ${TWREPORT}
	@ ${ECHO} Creating tripwire database
	@ cd ${TWCFG} && ${PREFIX}/sbin/tripwire --init
	@ ${ECHO} To create a floppy backup of your tripwire database
	@ ${ECHO} run \"make floppy\".  The default database will not
	@ ${ECHO} fit on a floppy, however with the removal of objects
	@ ${ECHO} from the database, it can be made to fit on a 1.44 MB
	@ ${ECHO} floppy disk.
	@ ${ECHO_CMD}
	@ ${ECHO} The tripwire database, configuration file and
	@ ${ECHO} policy file are signed using the local and site keys,
	@ ${ECHO} therefore according to the support staff at
	@ ${ECHO} tripwiresecurity.com, creating a floppy is not necessary.
	
.endif

floppy:
	@ disklabel -w -B /dev/rfd0c fd1440
	@ newfs -u 0 -t 0 -i 196608 -m 0 -T minimum -o space /dev/rfd0c
	@ mount /dev/fd0c /mnt
	@ ${CP} -p ${PREFIX}/sbin/tripwire /mnt/tripwire
	@ ${CP} -p ${TWCFG}/* /mnt
	@ ${SH} -c "${CP} -p ${TWDB}/* /mnt || exit 0"
	@ ${CHMOD} 555 /mnt/tripwire
	@ umount /mnt
	@ ${ECHO} Do not forget to remove and write-protect the floppy.

do-install:	install-software create-database

.include <bsd.port.post.mk>
