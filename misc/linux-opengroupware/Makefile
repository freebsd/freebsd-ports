# New ports collection makefile for:	linux-opengroupware.org
# Date created:				2003-07-20
# Whom:					Frank Reppin
#
# $FreeBSD$

PORTNAME=	opengroupware
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	misc www linux
MASTER_SITES=	http://www.opengroupware.org/packages/linux-opengroupware/RPMS/:ogo \
		http://www.opengroupware.org/packages/linux-opengroupware/NGOBJWEB/:ngo \
		${MASTER_SITE_REDHAT_LINUX}
MASTER_SITE_SUBDIR= updates/8.0/en/os/${MACHINE_ARCH}
PKGNAMEPREFIX=	linux-
DISTFILES=	${SET1} \
		${SET2} \
		${SET3}
EXTRACT_ONLY=	${NGOBJWEB_ADAPTOR}

MAINTAINER=	frank@opengroupware.org
COMMENT=	Groupware package including mail, calendar, palm sync and much more

INSTALL_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache2 \
		${LOCALBASE}/bin/psql:${PORTSDIR}/databases/postgresql7 \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash2 \
		${LINUXBASE}/lib/libc-2.3.2.so:${PORTSDIR}/emulators/linux_base-8 \
		${LOCALBASE}/bin/gmake:${PORTSDIR}/devel/gmake

#BEGINSET1

SET1=		opengroupware-core-4.2-ogo107.i386.rpm:ogo \
		opengroupware-core-tools-4.2-ogo107.i386.rpm:ogo \
		opengroupware-database-1.0-ogo022.i386.rpm:ogo \
		opengroupware-docapi-1.0-ogo101.i386.rpm:ogo \
		opengroupware-env-1.0-ogo016.i386.rpm:ogo \
		opengroupware-epoz-0.6.1-ogo003.i386.rpm:ogo \
		opengroupware-gstep-db-4.2-ogo042.i386.rpm:ogo \
		opengroupware-gstep-db-postgresql72-4.2-ogo042.i386.rpm:ogo \
		opengroupware-gstep-make-4.2-ogo009.i386.rpm:ogo \
		opengroupware-gstep-objc-2.95.3-ogo011.i386.rpm:ogo \
		opengroupware-js-1.5-ogo013.i386.rpm:ogo \
		opengroupware-libfoundation-1.0.25-ogo049.i386.rpm:ogo \
		opengroupware-libical-0.23.0-ogo010.i386.rpm:ogo \
		opengroupware-libxml2-2.6.11-ogo002.i386.rpm:ogo \
		opengroupware-libxslt-1.1.8-ogo002.i386.rpm:ogo \
		opengroupware-logic-1.0-ogo112.i386.rpm:ogo \
		opengroupware-nhsc-1.0-ogo001.i386.rpm:ogo \
		opengroupware-pda-1.0-ogo033.i386.rpm:ogo \
		opengroupware-pilot-link-0.10.99-ogo008.i386.rpm:ogo \
		opengroupware-plr-1.0-ogo008.i386.rpm:ogo \
		opengroupware-publisher-1.0-ogo020.i386.rpm:ogo \
		opengroupware-sope-4.2-ogo163.i386.rpm:ogo \
		opengroupware-theme-blue-de-1.0-ogo039.i386.rpm:ogo \
		opengroupware-theme-blue-en-1.0-ogo039.i386.rpm:ogo \
		opengroupware-theme-default-de-1.0-ogo039.i386.rpm:ogo \
		opengroupware-theme-default-dk-1.0-ogo039.i386.rpm:ogo \
		opengroupware-theme-default-en-1.0-ogo039.i386.rpm:ogo \
		opengroupware-theme-default-es-1.0-ogo039.i386.rpm:ogo \
		opengroupware-theme-default-it-1.0-ogo039.i386.rpm:ogo \
		opengroupware-theme-kde-en-1.0-ogo039.i386.rpm:ogo \
		opengroupware-theme-ooo-de-1.0-ogo039.i386.rpm:ogo \
		opengroupware-theme-ooo-en-1.0-ogo039.i386.rpm:ogo \
		opengroupware-theme-orange-de-1.0-ogo039.i386.rpm:ogo \
		opengroupware-theme-orange-en-1.0-ogo039.i386.rpm:ogo \
		opengroupware-tools-account-1.0-ogo031.i386.rpm:ogo \
		opengroupware-tools-aptnotify-1.0-ogo031.i386.rpm:ogo \
		opengroupware-tools-bulkmessages-1.0-ogo031.i386.rpm:ogo \
		opengroupware-tools-installsieve-1.0-ogo031.i386.rpm:ogo \
		opengroupware-webui-admin-1.0-ogo032.i386.rpm:ogo \
		opengroupware-webui-app-1.0-ogo054.i386.rpm:ogo \
		opengroupware-webui-common-1.0-ogo087.i386.rpm:ogo \
		opengroupware-webui-contact-1.0-ogo072.i386.rpm:ogo \
		opengroupware-webui-forms-1.0-ogo016.i386.rpm:ogo \
		opengroupware-webui-job-1.0-ogo037.i386.rpm:ogo \
		opengroupware-webui-libs-1.0-ogo059.i386.rpm:ogo \
		opengroupware-webui-mailer-1.0-ogo077.i386.rpm:ogo \
		opengroupware-webui-news-1.0-ogo018.i386.rpm:ogo \
		opengroupware-webui-prefs-1.0-ogo038.i386.rpm:ogo \
		opengroupware-webui-project-1.0-ogo077.i386.rpm:ogo \
		opengroupware-webui-resource-de-1.0-ogo132.i386.rpm:ogo \
		opengroupware-webui-resource-dk-1.0-ogo132.i386.rpm:ogo \
		opengroupware-webui-resource-en-1.0-ogo132.i386.rpm:ogo \
		opengroupware-webui-resource-es-1.0-ogo132.i386.rpm:ogo \
		opengroupware-webui-resource-fr-1.0-ogo132.i386.rpm:ogo \
		opengroupware-webui-resource-it-1.0-ogo132.i386.rpm:ogo \
		opengroupware-webui-resource-nl-1.0-ogo132.i386.rpm:ogo \
		opengroupware-webui-resource-pt_BR-1.0-ogo132.i386.rpm:ogo \
		opengroupware-webui-scheduler-1.0-ogo080.i386.rpm:ogo \
		opengroupware-xml-4.2-ogo066.i386.rpm:ogo \
		opengroupware-xml-STXSaxDriver-4.2-ogo066.i386.rpm:ogo \
		opengroupware-xml-icalsaxdriver-4.2-ogo066.i386.rpm:ogo \
		opengroupware-xml-libxmlsaxdriver-4.2-ogo066.i386.rpm:ogo \
		opengroupware-xmlrpcd-1.0-ogo049.i386.rpm:ogo \
		opengroupware-zidestore-1.2-ogo082.i386.rpm:ogo
#ENDSET1

SET2=		${NGOBJWEB_ADAPTOR}:ngo
SET3=		postgresql-libs-7.2.4-5.80.i386.rpm \
		openssl-0.9.6b-35.8.i386.rpm \
		cyrus-sasl-2.1.10-1.i386.rpm \
		openldap-2.0.27-2.8.0.i386.rpm \
		pam-0.75-46.8.0.i386.rpm \
		krb5-libs-1.2.5-15.i386.rpm

NGOBJWEB_ADAPTOR= opengroupware.org-mod_ngobjweb-200407092000.tar.gz
PATCHDIR?=	${MASTERDIR}/files
USE_LINUX=	yes
USE_GMAKE=	yes
MAKEFILE=	${WRKSRC}/opengroupware.org-mod_ngobjweb/GNUmakefile
BUILD_WRKSRC?=	${WRKSRC}/opengroupware.org-mod_ngobjweb
NGWEB_ADAP_DIR=	opengroupware.org-mod_ngobjweb
PKGNAME_PREFIX=	linux-

#CONFLICTS=	${PORTSDIR}/www/apache2 \
#		${PORTSDIR}/databases/postgresql7

ONLY_FOR_ARCHS=	i386
NO_PACKAGE=	We dont really build anything ...
DIST_SUBDIR=	ogo
PLIST=		${WRKDIR}/pkg-plist
MD5_FILE=	${MASTERDIR}/distinfo.${MACHINE_ARCH}
PREFIX=		${LINUXBASE}

.include <bsd.port.pre.mk>

RPM2CPIO?=	${LOCALBASE}/bin/rpm2cpio
CPIOFLAGS=	--extract --make-directories --no-absolute-filenames \
		--preserve-modification-time --quiet
RPMDIR=		${DISTDIR}/${DIST_SUBDIR}

REMOVEFILES=	.md5sum .md5sum.changes \
		${NGOBJWEB_ADAPTOR} \
		etc/rc.d/init.d/saslauthd \
		usr/sbin/dbconverter-2 \
		usr/sbin/saslauthd \
		usr/sbin/sasldblistusers \
		usr/sbin/sasldblistusers2 \
		usr/sbin/saslpasswd \
		usr/sbin/saslpasswd2 \
		sbin/pam_console_apply \
		sbin/pam_tally \
		sbin/pam_timestamp_check \
		sbin/pwdb_chkpwd \
		sbin/unix_chkpwd \
		etc/krb5.conf \
		etc/rc.d/init.d/kdcrotate \
		usr/bin/openssl

REMOVEDIRS=	${NGWEB_ADAP_DIR} \
		etc/openldap \
		usr/share/openldap \
		usr/kerberos/share

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${EXTRACT_ONLY} ${WRKSRC}
	@(cd ${WRKSRC} && ${TAR} xfz ${EXTRACT_ONLY})

	@for myfile in ${SET1} ${SET3}; do \
		ourfile=`${ECHO} $$myfile |${SED} -e 's/:ogo//'`; \
		${ECHO} "Extracting for: $$ourfile"; \
		(cd ${WRKSRC} && ${RPM2CPIO} ${RPMDIR}/$$ourfile | ${CPIO} ${CPIOFLAGS}); \
	done

post-build:
	${INSTALL} ${COPY} -m 644 ${WRKSRC}/${NGWEB_ADAP_DIR}/ngobjweb*.so ${WRKSRC}/opt/opengroupware.org

	@for delfile in ${REMOVEFILES}; do \
		${ECHO} "Removing unecessary file in ${WRKSRC}: $$delfile"; \
		${RM} -f ${WRKSRC}/$$delfile; \
	done

	@for deldir in ${REMOVEDIRS}; do \
		${ECHO} "Removing unecessary dir in ${WRKSRC}: $$deldir"; \
		${RM} -rf ${WRKSRC}/$$deldir; \
	done

.if !defined(EXTRACT_PRESERVE_OWNERSHIP)
	@if [ `id -u` = 0 ]; then \
		${CHMOD} -R ug-s ${WRKDIR}; \
		${CHOWN} -R 0:0 ${WRKDIR}; \
	fi
.endif

pre-install:
	${RM} -f ${PLIST}
	cd ${WRKSRC} && ${FIND} -s . -type f -o -type l | \
		${CUT} -c3-999 >> ${PLIST} \
		&& ${FIND} -d * -type d | ${SED} -e 's:^:@dirrm :' >> ${PLIST}

do-install:
	cd ${WRKSRC} && ${FIND} * | ${CPIO} -dlmp ${PREFIX}
	${FIND} ${PREFIX} -type d \! -ipath '${LINUXBASE}/proc*' -exec ${CHMOD} 755 \{\} \;

post-install:
	@${MKDIR} ${LINUXBASE}/opt/opengroupware.org/documents
	@${CHMOD} 750 ${LINUXBASE}/opt/opengroupware.org/documents
	@${MKDIR} ${LINUXBASE}/opt/opengroupware.org/news
	@${CHMOD} 750 ${LINUXBASE}/opt/opengroupware.org/news
	@${ECHO} '/opt/skyrix/system/Libraries/ix86/linux-gnu/gnu-fd-nil' >>${LINUXBASE}/etc/ld.so.conf
	@${ECHO} '/opt/opengroupware.org/Libraries/ix86/linux-gnu/gnu-fd-nil' >>${LINUXBASE}/etc/ld.so.conf
	@${ECHO} '/usr/kerberos/lib' >>${LINUXBASE}/etc/ld.so.conf
	@${LN} -sf ${LINUXBASE}/usr/lib/libpq.so.2 ${LINUXBASE}/usr/lib/libpq.so.3
	@${PREFIX}/sbin/ldconfig
	@${SH} ${PKGDIR}/pkg-install ${PKGNAME} POST-INSTALL
	@${CHOWN} -Rh ogo:skyrix ${LINUXBASE}/opt/skyrix
	@${CHOWN} -Rh ogo:skyrix ${LINUXBASE}/opt/opengroupware.org
	@${INSTALL} -d -m 770 -o ogo -g skyrix /var/log/opengroupware
	@${CHOWN} -Rh ogo:skyrix /var/log/opengroupware
	@${INSTALL} -m 640 -o ogo -g skyrix ${FILESDIR}/OpenGroupware.org.sh.tmpl ${LINUXBASE}/opt/opengroupware.org/OpenGroupware.org.sh
	@${SH} ${PKGDIR}/pkg-install ${PKGNAME} WRITE-DEFAULTS-FIRSTTIME
	@${SH} ${PKGDIR}/pkg-install ${PKGNAME} COPY-TEMPLATES
	@${CHOWN} -Rh ogo:skyrix ${LINUXBASE}/opt/opengroupware.org/.libFoundation
	@${INSTALL} -m 500 -o root -g wheel ${FILESDIR}/ogo.sh.sample ${LOCALBASE}/etc/rc.d/ogo.sh.sample
	@${INSTALL} -m 500 -o root -g wheel ${FILESDIR}/zidestore.sh.sample ${LOCALBASE}/etc/rc.d/zidestore.sh.sample
	@${INSTALL} -m 500 -o root -g wheel ${FILESDIR}/xmlrpcd.sh.sample ${LOCALBASE}/etc/rc.d/xmlrpcd.sh.sample
	@${INSTALL} -m 500 -o root -g wheel ${FILESDIR}/nhsd.sh.sample ${LOCALBASE}/etc/rc.d/nhsd.sh.sample
	@${PERL} ${SCRIPTDIR}/patch_apache_version.pl
	@${CHOWN} -Rh ogo:skyrix ${LINUXBASE}/opt/opengroupware.org/OpenGroupware.org.apacheinclude
	@${INSTALL} -m 444 -o ogo -g skyrix ${FILESDIR}/INSTALL.fbsd ${LINUXBASE}/opt/opengroupware.org/INSTALL.fbsd
	@${ECHO} ''
	@fmt ${PKGMESSAGE}
	@${ECHO} ''

.include <bsd.port.post.mk>
