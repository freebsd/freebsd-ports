# Created by: Alexander Moisseev <moiseev@mezonplus.ru>
# $FreeBSD$

PORTNAME=	backuppc
PORTVERSION=	3.3.0
CATEGORIES=	sysutils
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	BackupPC-${PORTVERSION}

MAINTAINER=	moiseev@mezonplus.ru
COMMENT=	System for backing PCs and laptops to a server

RUN_DEPENDS=	p5-File-Listing>=0:${PORTSDIR}/sysutils/p5-File-Listing

USE_RC_SUBR=	backuppc

USES=		perl5
NO_BUILD=	yes

USERS=		backuppc
GROUPS=		backuppc

BPC_CGIDIR?=	${PREFIX}/www/cgi-bin
BPC_DATADIR?=	/var/db/BackupPC

PLIST_SUB=	BPC_CGIDIR=${BPC_CGIDIR:S,^${PREFIX}/,,} BPC_DATADIR=${BPC_DATADIR}

PORTDOCS=	ChangeLog LICENSE README BackupPC.html BackupPC.pod

MAN1=		${PORTNAME}.1

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
		-e 's,/etc/BackupPC/config.pl,${ETCDIR}/config.pl,' \
		-e 's|Conf{ConfDir}/hosts", 0644)|Conf{ConfDir}/hosts.sample", 0644)|' \
		${WRKSRC}/configure.pl
	@${REINPLACE_CMD} \
		-e 's,"/doc/BackupPC.html","/${DOCSDIR_REL}/BackupPC.html",' \
		${WRKSRC}/lib/BackupPC/CGI/View.pm
	@${REINPLACE_CMD} \
		-e 's,STDERR "Please su ,STDERR "Please su [-m] ,' \
		${WRKSRC}/lib/BackupPC/Lib.pm
	@${REINPLACE_CMD} \
		-e 's, you can use the -s, you can use the -m,' \
		-e 's,option to su to explicitly run,option to su to run,' \
		-e 's,su -s /bin/bash __BACKUPPCUSER__,su -m __BACKUPPCUSER__,' \
		${WRKSRC}/doc/BackupPC.html ${WRKSRC}/doc/BackupPC.pod

pre-install:
	@${ECHO_MSG}
	@${ECHO_MSG} ">>> -----------------------------------------------------------------------"
	@${ECHO_MSG} ">>> You can use the following variables to tweak installation-time options:"
	@${ECHO_MSG} ">>>	BPC_CGIDIR"
	@${ECHO_MSG} ">>>	BPC_DATADIR"
	@${ECHO_MSG} ">>> -----------------------------------------------------------------------"
	@${ECHO_MSG} ">>> If this is an upgrade make sure the full path of the existing BackupPC"
	@${ECHO_MSG} ">>> configuration directory is ${ETCDIR}"
	@${ECHO_MSG} ">>> -----------------------------------------------------------------------"
	@${ECHO_MSG}

do-install:
	@cd ${WRKSRC} && ${PERL} configure.pl	\
		--batch				\
		--backuppc-user ${USERS}	\
		--config-dir ${ETCDIR}		\
		--cgi-dir ${BPC_CGIDIR}		\
		--data-dir ${BPC_DATADIR}	\
		--fhs				\
		--html-dir ${WWWDIR}		\
		--html-dir-url /${PORTNAME}	\
		--install-dir ${PREFIX}		\
		--log-dir /var/log/BackupPC

post-install:
	@${EXEC} pod2man --section=1 --release=${PORTVERSION} --name=BackupPC --center=BackupPC" user guide" ${WRKSRC}/BackupPC.pod ${WRKSRC}/${PORTNAME}.1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR}
.endif

	@${MV} ${ETCDIR}/config.pl ${ETCDIR}/config.pl.sample

	@${ECHO_MSG}
	@${ECHO_MSG} ">>> ----------------------------------------------------------"
	@${ECHO_MSG} ">>> You need to copy and customize"
	@${ECHO_MSG} ">>> # cp -p ${ETCDIR}/config.pl.sample ${ETCDIR}/config.pl"

	@if [ ! -f ${ETCDIR}/hosts ]; then \
		${ECHO_MSG} ">>> # cp -p ${ETCDIR}/hosts.sample ${ETCDIR}/hosts"; \
	fi

	@${ECHO_MSG} ">>>"
	@${ECHO_MSG} ">>> Add the following line to /etc/rc.conf to enable BackupPC:"
	@${ECHO_MSG} ">>> backuppc_enable=\"YES\""
	@${ECHO_MSG} ">>>"
	@${ECHO_MSG} ">>> Data directory is ${BPC_DATADIR}"
	@${ECHO_MSG} ">>> This is where all the PC backup data is stored."
	@${ECHO_MSG} ">>> This file system needs to be big enough"
	@${ECHO_MSG} ">>> to accommodate all the PCs you expect to backup."
	@${ECHO_MSG} ">>> ----------------------------------------------------------"
	@${ECHO_MSG}

.include <bsd.port.mk>
