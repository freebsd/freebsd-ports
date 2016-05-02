# Created by: Alexander Moisseev <moiseev@mezonplus.ru>
# $FreeBSD$

PORTNAME=	backuppc
PORTVERSION=	3.3.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF
DISTNAME=	BackupPC-${PORTVERSION}

MAINTAINER=	moiseev@mezonplus.ru
COMMENT=	Multi-platform backup to disk-based storage

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-File-Listing>=0:sysutils/p5-File-Listing

CONFLICTS=	backuppc-devel-[0-9]*

USE_RC_SUBR=	backuppc

USES=		cpe perl5
CPE_VENDOR=	craig_barratt
NO_BUILD=	yes

USERS=		backuppc
GROUPS=		backuppc

CGIDIR?=	${PREFIX}/www/cgi-bin

SUB_FILES=	pkg-deinstall pkg-message update.sh
SUB_LIST=	CGIDIR=${CGIDIR}

PLIST_SUB+=	CGIDIR=${CGIDIR:S,^${PREFIX}/,,} \
		DISTVERSION=${DISTVERSION}

PORTDOCS=	ChangeLog LICENSE README

OPTIONS_DEFINE=		ARCHIVE_ZIP COMPRESS_ZLIB DOCS FILE_RSYNCP NMBLOOKUP \
			SMBCLIENT XML_RSS

OPTIONS_RADIO=		GRAPHS
OPTIONS_RADIO_GRAPHS=	RRD_GRAPHS RRDTOOL

OPTIONS_DEFAULT=	ARCHIVE_ZIP COMPRESS_ZLIB RRD_GRAPHS

ARCHIVE_ZIP_DESC=	Perl module for Zip archive files
COMPRESS_ZLIB_DESC=	Perl5 interface to zlib compression library
FILE_RSYNCP_DESC=	Perl Rsync client
NMBLOOKUP_DESC=		NetBIOS Name lookup tool
RRD_GRAPHS_DESC=	Apply graphs patch (but not install RRDTool)
RRDTOOL_DESC=		Use RRDTool to generate pool statistic graphs
SMBCLIENT_DESC=		Samba client
XML_RSS_DESC=		Perl extension to manage RSS files

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MARCHIVE_ZIP}
RUN_DEPENDS+=	p5-Archive-Zip>=0:archivers/p5-Archive-Zip
.endif
.if ${PORT_OPTIONS:MCOMPRESS_ZLIB}
RUN_DEPENDS+=	p5-IO-Compress>=0:archivers/p5-IO-Compress
.endif
.if ${PORT_OPTIONS:MFILE_RSYNCP}
RUN_DEPENDS+=	p5-File-RsyncP>=0:net/p5-File-RsyncP
.endif
.if ${PORT_OPTIONS:MNMBLOOKUP}
RUN_DEPENDS+=	nmblookup:net/samba-nmblookup
.endif
.if ${PORT_OPTIONS:MRRDTOOL}
RUN_DEPENDS+=	rrdtool:databases/rrdtool
.endif
.if ${PORT_OPTIONS:MRRD_GRAPHS} || ${PORT_OPTIONS:MRRDTOOL}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bin-BackupPC \
		${FILESDIR}/extra-patch-lib-BackupPC-CGI-GeneralInfo.pm
.endif
.if ${PORT_OPTIONS:MSMBCLIENT}
RUN_DEPENDS+=	smbclient:net/samba-smbclient
.endif
.if ${PORT_OPTIONS:MXML_RSS}
RUN_DEPENDS+=	p5-XML-RSS>=0:textproc/p5-XML-RSS
.endif

pre-patch:
	@${CP} ${WRKSRC}/configure.pl ${WRKSRC}/update.pl

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/etc/BackupPC\(/config.pl\)|${ETCDIR}\1|' \
		-e 's|^\(foreach my $$dir ( qw(bin \)doc$$|\1${DOCSDIR_REL}|' \
		-e 's|\($$DestDir$$Conf{InstallDir}/\)doc|\1${DOCSDIR_REL}|' \
		${WRKSRC}/configure.pl ${WRKSRC}/update.pl
	@${REINPLACE_CMD} -E \
		-e 's|^(use lib ")\.(/lib";)$$|\1${PREFIX}\2|' \
		${WRKSRC}/update.pl
	@${REINPLACE_CMD} \
		-e 's|STDERR "Please su |STDERR "Please su [-m] |' \
		${WRKSRC}/lib/BackupPC/Lib.pm
	@${REINPLACE_CMD} \
		-e 's| you can use the -s| you can use the -m|' \
		-e 's|option to su to explicitly run|option to su to run|' \
		-e 's|su -s /bin/bash __BACKUPPCUSER__|su -m __BACKUPPCUSER__|' \
		${WRKSRC}/doc/BackupPC.html ${WRKSRC}/doc/BackupPC.pod

do-install:
	cd ${WRKSRC} && ${PERL} configure.pl	\
		--batch				\
		--backuppc-user ${USERS}	\
		--bin-path perl=${PERL}		\
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
	${CP} ${WRKSRC}/doc/BackupPC.html ${STAGEDIR}${WWWDIR}
	${RM} ${STAGEDIR}${ETCDIR}/config.pl
	${RM} ${STAGEDIR}${ETCDIR}/hosts
	${CP} ${WRKSRC}/conf/config.pl ${STAGEDIR}${ETCDIR}/config.pl.sample
	${CP} ${WRKSRC}/conf/hosts ${STAGEDIR}${ETCDIR}/hosts.sample
	${CP} ${WRKDIR}/update.sh ${STAGEDIR}${ETCDIR}/update.sh
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/backuppc
	${CP} ${WRKSRC}/update.pl ${STAGEDIR}${PREFIX}/libexec/backuppc/update.pl

.include <bsd.port.mk>
