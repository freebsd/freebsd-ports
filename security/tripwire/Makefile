# New ports collection makefile for:	tripwire 2.3.1
# Date created:		Tue Mar  6 06:57:58 PST 2001
# Whom:			Cy Schubert <Cy.Schubert@uumail.gov.bc.ca>
#
# $FreeBSD$
#

PORTNAME=	tripwire
PORTVERSION=	2.4.1.2
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTNAME}-${PORTVERSION}-src
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	cy@FreeBSD.org
COMMENT=	File system security and verification program

LATEST_LINK=	${PORTNAME}
MAN5=		twfiles.5 twconfig.5 twpolicy.5
MAN8=		siggen.8 tripwire.8 twadmin.8 twintro.8 twprint.8
NO_PACKAGE=	"requires local database to be built"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	SYSPRE=${ARCH}-unknown-freebsd
IS_INTERACTIVE=	yes
M4=		/usr/bin/m4

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
TWPOL_TXT?=	${FILESDIR}/twpol.m4
# Other variables that are used:
TRIPWIRE_CLOBBER?=	NO
#	If TRIPWIRE_CLOBBER is set to YES, the install script clobbers
#	previously installed config files.
CONFIGURE_ARGS=	--prefix=${PREFIX} --program-transform-name='' --sysconfdir=${TWCFG}

PLIST_SUB+=	TWCFG=${TWCFG} TWDB=${TWDB}

pre-configure:
	@ ${M4} -DFREEBSD_VERSION=`${ECHO_CMD} ${OSREL} | ${CUT} -d. -f1` < ${TWPOL_TXT} > ${WRKSRC}/policy/twpol-FreeBSD.txt
	@ ${MV} ${WRKSRC}/src/core/stdcore.h ${WRKSRC}/src/core/stdcore.h.orig
	@ ${SED} 's%^# define CONFIG_FILE_ROOT	"/usr/local/etc/tripwire"%# define CONFIG_FILE_ROOT	"${TWCFG}"%' ${WRKSRC}/src/core/stdcore.h.orig > ${WRKSRC}/src/core/stdcore.h
	@ ${MV} ${WRKSRC}/man/man4/twconfig.4 ${WRKSRC}/man/man5/twconfig.5
	@ ${MV} ${WRKSRC}/man/man4/twpolicy.4 ${WRKSRC}/man/man5/twpolicy.5
	@ ${LN} -s ${WRKSRC}/contrib ${WRKSRC}/install

install-config-files:
	@ ${ECHO_CMD} TWPOLICY=${TWPOLICY} >> ${WRKSRC}/install/install.cfg
	@ ${ECHO_CMD} TWSITEKEYDIR=${TWSITEKEYDIR} >> ${WRKSRC}/install/install.cfg
	@ ${ECHO_CMD} TWLOCALKEYDIR=${TWLOCALKEYDIR} >> ${WRKSRC}/install/install.cfg
	@ ${ECHO_CMD} TWDB=${TWDB} >> ${WRKSRC}/install/install.cfg
	@ ${ECHO_CMD} TWREPORT=${TWREPORT} >> ${WRKSRC}/install/install.cfg
	@ ${ECHO_CMD} TWEDITOR=${TWEDITOR} >> ${WRKSRC}/install/install.cfg
	@ cd ${WRKSRC} && ${LN} -sf install/install.cfg install/install.sh .
.if ( defined(TRIPWIRE_CLOBBER) && ${TRIPWIRE_CLOBBER} == "YES" ) || \
    ( defined(TRIPWIRE_CLOBBER) && ${TRIPWIRE_CLOBBER} == "yes" )
	@ cd ${WRKSRC} && PREFIX=${PREFIX} CLOBBER=true ${GMAKE} install-data-hook
.else
	@ cd ${WRKSRC} && PREFIX=${PREFIX} ${GMAKE} install-data-hook
.endif

create-database:
.ifndef NO_DB_BUILD
	@ ${MKDIR} -p ${TWCFG} ${TWPOLICY} ${TWSITEKEYDIR} ${TWLOCALKEYDIR} \
		${TWDB} ${TWREPORT}
	@ ${ECHO} Creating tripwire database
	@ cd ${TWCFG} && ${PREFIX}/sbin/tripwire --init
	@ ${ECHO_CMD}
	@ ${ECHO} The tripwire database, configuration file and
	@ ${ECHO} policy file are signed using the local and site keys,
	@ ${ECHO} therefore according to the support staff at
	@ ${ECHO} tripwiresecurity.com, creating a floppy is not necessary.
	
.endif

post-install:	install-config-files create-database

.include <bsd.port.mk>
