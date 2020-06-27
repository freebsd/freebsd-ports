# Created by: Alexander Moisseev <moiseev@mezonplus.ru>
# $FreeBSD$

PORTNAME=	backuppc
PORTVERSION=	4.4.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/backuppc/backuppc/releases/download/${PORTVERSION}/ \
		SF
PKGNAMESUFFIX=	4
DISTNAME=	BackupPC-${DISTVERSION}

MAINTAINER=	moiseev@mezonplus.ru
COMMENT=	Multi-platform backup to disk-based storage

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-CGI>0:www/p5-CGI \
		p5-File-Listing>=0:sysutils/p5-File-Listing \
		p5-BackupPC-XS>=0.62:sysutils/p5-BackupPC-XS

USES=		perl5

CONFLICTS_INSTALL=	backuppc backuppc-devel

NO_BUILD=	yes
NO_ARCH=	yes
USE_RC_SUBR=	backuppc

USERS=		backuppc
GROUPS=		backuppc

DOCSDIR=	${PREFIX}/share/doc/BackupPC
CGIDIR?=	${PREFIX}/www/cgi-bin

SUB_FILES=	pkg-deinstall pkg-message update.sh
SUB_LIST=	CGIDIR=${CGIDIR}

PLIST_SUB+=	CGIDIR=${CGIDIR:S,^${PREFIX}/,,} \
		DISTVERSION=${DISTVERSION}

PORTDOCS=	ChangeLog LICENSE README.md

OPTIONS_DEFINE=		ARCHIVE_ZIP DOCS RSYNC_BPC \
			RRDTOOL SMB XML_RSS

OPTIONS_DEFAULT=	ARCHIVE_ZIP

ARCHIVE_ZIP_DESC=	Install Perl module for Zip archive files
RSYNC_BPC_DESC=		Install modified rsync that used as part of BackupPC
RRDTOOL_DESC=		Install Round Robin Database Tools
SMB_DESC=		Install Samba (for "smb" transfer and NetBIOS lookup)
XML_RSS_DESC=		Install Perl extension to manage RSS files

ARCHIVE_ZIP_RUN_DEPENDS=	p5-Archive-Zip>=0:archivers/p5-Archive-Zip
RSYNC_BPC_RUN_DEPENDS=		rsync-bpc>=3.0.9.15:net/rsync-bpc
RRDTOOL_RUN_DEPENDS=		rrdtool:databases/rrdtool
SMB_USES=			samba:run # nmblookup, smbclient
XML_RSS_RUN_DEPENDS=		p5-XML-RSS>=0:textproc/p5-XML-RSS

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
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/doc/BackupPC.html ${STAGEDIR}${WWWDIR}
	${RM} ${STAGEDIR}${ETCDIR}/config.pl
	${RM} ${STAGEDIR}${ETCDIR}/hosts
	${CP} ${WRKDIR}/update.sh ${STAGEDIR}${ETCDIR}/update.sh
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/backuppc
	${CP} ${WRKSRC}/configure.pl ${STAGEDIR}${PREFIX}/libexec/backuppc/configure.pl

.include <bsd.port.mk>
