# Created by: Alexander Moisseev <moiseev@mezonplus.ru>
# $FreeBSD$

PORTNAME=	backuppc
PORTVERSION=	3.3.0
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	BackupPC-${PORTVERSION}

MAINTAINER=	moiseev@mezonplus.ru
COMMENT=	System for backing PCs and laptops to a server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-File-Listing>=0:${PORTSDIR}/sysutils/p5-File-Listing

CONFLICTS=	backuppc-devel-[0-9]*

USE_RC_SUBR=	backuppc

USES=		perl5
NO_BUILD=	yes
NO_PACKAGE=	Overwrites configuration files; set FORCE_PACKAGE if you want\
		to build this package

USERS=		backuppc
GROUPS=		backuppc

CGIDIR?=	${PREFIX}/www/cgi-bin

SUB_FILES=	pkg-deinstall pkg-message

PLIST_SUB+=	CGIDIR=${CGIDIR:S,^${PREFIX}/,,} \
		DISTVERSION=${DISTVERSION}

PORTDOCS=	ChangeLog LICENSE README

OPTIONS_DEFINE=		ARCHIVE_ZIP COMPRESS_ZLIB DOCS FILE_RSYNCP NMBLOOKUP \
			RRDTOOL SMBCLIENT XML_RSS
OPTIONS_DEFAULT=	ARCHIVE_ZIP COMPRESS_ZLIB

ARCHIVE_ZIP_DESC=	Perl module for Zip archive files
COMPRESS_ZLIB_DESC=	Perl5 interface to zlib compression library
FILE_RSYNCP_DESC=	Perl Rsync client
NMBLOOKUP_DESC=		NetBIOS Name lookup tool
RRDTOOL_DESC=		Use RRDTool to generate pool statistic graphs
SMBCLIENT_DESC=		Samba client
XML_RSS_DESC=		Perl extension to manage RSS files

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MARCHIVE_ZIP}
RUN_DEPENDS+=	p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip
.endif
.if ${PORT_OPTIONS:MCOMPRESS_ZLIB}
RUN_DEPENDS+=	p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress
.endif
.if ${PORT_OPTIONS:MFILE_RSYNCP}
RUN_DEPENDS+=	p5-File-RsyncP>=0:${PORTSDIR}/net/p5-File-RsyncP
.endif
.if ${PORT_OPTIONS:MNMBLOOKUP}
RUN_DEPENDS+=	nmblookup:${PORTSDIR}/net/samba-nmblookup
.endif
.if ${PORT_OPTIONS:MRRDTOOL}
RUN_DEPENDS+=	rrdtool:${PORTSDIR}/databases/rrdtool
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bin-BackupPC \
		${FILESDIR}/extra-patch-lib-BackupPC-CGI-GeneralInfo.pm
.endif
.if ${PORT_OPTIONS:MSMBCLIENT}
RUN_DEPENDS+=	smbclient:${PORTSDIR}/net/samba-smbclient
.endif
.if ${PORT_OPTIONS:MXML_RSS}
RUN_DEPENDS+=	p5-XML-RSS>=0:${PORTSDIR}/textproc/p5-XML-RSS
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/etc/BackupPC\(/config.pl\)|${ETCDIR}\1|' \
		-e 's|^\(foreach my $$dir ( qw(bin \)doc$$|\1${DOCSDIR_REL}|' \
		-e 's|\($$DestDir$$Conf{InstallDir}/\)doc|\1${DOCSDIR_REL}|' \
		${WRKSRC}/configure.pl
	@${REINPLACE_CMD} \
		-e 's,"/doc/BackupPC.html","/${DOCSDIR_REL}/BackupPC.html",' \
		${WRKSRC}/lib/BackupPC/CGI/View.pm
	@${REINPLACE_CMD} \
		-e 's|STDERR "Please su |STDERR "Please su [-m] |' \
		${WRKSRC}/lib/BackupPC/Lib.pm
	@${REINPLACE_CMD} \
		-e 's| you can use the -s| you can use the -m|' \
		-e 's|option to su to explicitly run|option to su to run|' \
		-e 's|su -s /bin/bash __BACKUPPCUSER__|su -m __BACKUPPCUSER__|' \
		${WRKSRC}/doc/BackupPC.html ${WRKSRC}/doc/BackupPC.pod

do-install:
	if [ -f ${ETCDIR}/config.pl ]; then \
		${MKDIR} ${STAGEDIR}${ETCDIR}; \
		${CP} -p ${ETCDIR}/config.pl ${STAGEDIR}${ETCDIR}/config.pl; \
	fi
	if [ -f ${ETCDIR}/hosts ]; then \
		${MKDIR} ${STAGEDIR}${ETCDIR}; \
		${CP} -p ${ETCDIR}/hosts ${STAGEDIR}${ETCDIR}/hosts; \
	fi

	cd ${WRKSRC} && ${PERL} configure.pl	\
		--batch				\
		--backuppc-user ${USERS}	\
		--config-dir ${ETCDIR}		\
		--cgi-dir ${CGIDIR}		\
		--data-dir /var/db/BackupPC	\
		--dest-dir ${STAGEDIR}		\
		--fhs				\
		--html-dir ${WWWDIR}		\
		--html-dir-url /${PORTNAME}	\
		--install-dir ${PREFIX}		\
		--log-dir /var/log/BackupPC	\
		--no-set-perms			\
		--uid-ignore

	pod2man --section=1 --release=${PORTVERSION} \
		--name=BackupPC --center="BackupPC user guide" \
		${WRKSRC}/doc/BackupPC.pod ${WRKSRC}/${PORTNAME}.1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

	if [ ! -f ${STAGEDIR}${ETCDIR}/config.pl.pre-${DISTVERSION} ]; then \
		> ${STAGEDIR}${ETCDIR}/config.pl.pre-${DISTVERSION}; \
	fi
	${INSTALL} -d ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	cd ${STAGEDIR}${ETCDIR} && \
		${CHGRP} wheel config.pl config.pl.pre-${DISTVERSION} && \
		${MV} config.pl hosts config.pl.pre-${DISTVERSION} \
			${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/

.include <bsd.port.mk>
