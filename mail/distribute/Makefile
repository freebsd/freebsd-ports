# New ports collection makefile for:	distribute
# Date created:		1 Oct 1997
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#

PORTNAME=	distribute
PORTVERSION= 	2.1.26
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.foretune.co.jp/pub/network/mail/distribute/
DISTNAME=	${PORTNAME}-2.1-pl19

PATCH_SITES=	${MASTER_SITES}BETA/
PATCHFILES=	patch.20.gz patch.21e.gz patch.22e.gz patch.23e.gz \
		patch.24e.gz patch.25e.gz patch.26e.gz

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Mail dispatcher for mailing list.  Fits nicely with majordomo

BUILD_DEPENDS=	${LOCALBASE}/lib/libmimekit.a:${PORTSDIR}/japanese/mimekit

WRKSRC=		${WRKDIR}/distribute-pl19
MAN1=		distribute.1
DIST_SUBDIR=	distribute
# Compile time configuration required.
IS_INTERACTIVE=	YES

# customize below if you would like to
MAILINGLIST_DIR?=	${PREFIX}/majordomo/lists
MAJORDOMO_DIR?=		${PREFIX}/majordomo	# mail/majordomo likes this
MAJORDOMO_LIST_DIR?=	${MAJORDOMO_DIR}/lists
ARCHIVE_DIR?=		/var/spool/mail-list
DEF_DOMAINNAME?=	your.domain.here
DISTRIBUTE_OWNER?=	majordom		# owner of distribute
DISTRIBUTE_GROUP?=	majordom		# group of distribute

MAKE_ENV+=	DEFAULTCONFIG="-DDEF_SEQ_PATH=\\\"$(MAILINGLIST_DIR)\\\" \
			-DDEF_RECIPIENT_PATH=\\\"$(MAILINGLIST_DIR)\\\" \
			-DDEF_MAJORDOMO_RECIPIENT_PATH=\\\"$(MAJORDOMO_LIST_DIR)\\\" \
			-DDEF_DOMAINNAME=\\\"$(DEF_DOMAINNAME)\\\" \
			-DDEF_ARCHIVE_PATH=\\\"$(ARCHIVE_DIR)\\\"" \
		DISTRIBUTE_OWNER="${DISTRIBUTE_OWNER}" \
		DISTRIBUTE_GROUP="${DISTRIBUTE_GROUP}" \
		INSTALL="${INSTALL}" \
		INSTALL_MAN="${INSTALL_MAN}"

post-build: message
post-install: message
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/distribute
	@ for file in BugList COPYRIGHT CREDITS ChangeLog INSTALL.JP NEWS \
	  OPTIONS README README.FIRST ToDo; do \
	    ${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/share/doc/distribute; \
	done
.endif

message::
	@${ECHO} "===> distribute was compiled with the following configuration:"
	@${ECHO} "     membership file directory: ${MAILINGLIST_DIR}"
	@${ECHO} "     membership file directory: ${MAJORDOMO_LIST_DIR} (for majordomo)"
	@${ECHO} "     archiving directory: ${ARCHIVE_DIR}"
	@${ECHO} "     if necessery, override them and perform compilation again."
	@${ECHO} "     there's no way to override them at runtime."

.include <bsd.port.mk>
