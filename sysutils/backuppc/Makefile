# New ports collection makefile for:	BackupPC
# Date created:				19 Aug 2010
# Whom:					Alexander Moisseev <moiseev@mezonplus.ru>
#
# $FreeBSD$
#

PORTNAME=	backuppc
PORTVERSION=	3.2.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	BackupPC-${PORTVERSION}

MAINTAINER=	moiseev@mezonplus.ru
COMMENT=	System for backing PCs and laptops to a server

NO_BUILD=	yes

USE_PERL5=	5.8.0+
USE_RC_SUBR=	backuppc

USERS=		backuppc
GROUPS=		backuppc

BPC_CGIDIR?=	${PREFIX}/www/cgi-bin
BPC_DATADIR?=	/var/db/BackupPC

PORTDOCS=	ChangeLog LICENSE README BackupPC.html BackupPC.pod

MAN1=		${PORTNAME}.1

OPTIONS=	COMPRESS_ZLIB "Perl5 interface to zlib compression library"	on \
		ARCHIVE_ZIP "Perl module for Zip archive files"			on \
		FILE_RSYNCP "Perl Rsync client"					off \
		SMBCLIENT "Samba client"					off \
		NMBLOOKUP "NetBIOS Name lookup tool"				off \
		LIBWWW "Perl5 library for WWW access (for FTP Xfer)"		off \
		XML_RSS "Perl extension to manage RSS files"			off

.include <bsd.port.options.mk>

.if defined(WITH_COMPRESS_ZLIB)
RUN_DEPENDS+=	p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress
.endif
.if defined(WITH_ARCHIVE_ZIP)
RUN_DEPENDS+=	${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip
.endif
.if defined(WITH_FILE_RSYNCP)
RUN_DEPENDS+=	${SITE_PERL}/mach/File/RsyncP.pm:${PORTSDIR}/net/p5-File-RsyncP
.endif
.if defined(WITH_SMBCLIENT)
RUN_DEPENDS+=	smbclient:${PORTSDIR}/net/samba-smbclient
.endif
.if defined(WITH_NMBLOOKUP)
RUN_DEPENDS+=	nmblookup:${PORTSDIR}/net/samba-nmblookup
.endif
.if defined(WITH_LIBWWW)
RUN_DEPENDS+=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
.endif
.if defined(WITH_XML_RSS)
RUN_DEPENDS+=	${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's,/etc/BackupPC/config.pl,${ETCDIR}/config.pl,' \
		-e 's|Conf{ConfDir}/hosts", 0644)|Conf{ConfDir}/hosts.sample", 0644)|' \
		${WRKSRC}/configure.pl
	@${REINPLACE_CMD} \
		-e 's,"/doc/BackupPC.html","/${DOCSDIR_REL}/BackupPC.html",' \
		${WRKSRC}/lib/BackupPC/CGI/View.pm

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

.if !defined(NOPORTDOCS)
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
