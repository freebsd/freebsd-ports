# New ports collection makefile for:   spamass-milter
# Date created:        29 April 2002
# Whom:                Eugene M. Kim <ab@astralblue.net>
#
# $FreeBSD$
#

PORTNAME=	spamass-milter
PORTVERSION=	0.3.1
PORTREVISION=	10
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	spamass-milt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sendmail Milter (mail filter) plugin for SpamAssassin

BUILD_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=	yes

##
# Use the following quirks to choose which sendmail to use (ports or system):
#
#   WITH_SENDMAIL_BASE=yes
# or
#   WITH_SENDMAIL_PORT=yes
#
# If unspecified, give base precedence.
#

.include <bsd.port.pre.mk>

.if defined(WITH_ADDAUTH_PATCH)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-addauth
.endif

.if defined(WITH_REJECTTEXT_PATCH)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-rejecttext1
.if defined(WITH_ADDAUTH_PATCH)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-rejecttext2a
.else
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-rejecttext2
.endif
.endif

.if exists(${LOCALBASE}/lib/libldap.so)
WITH_LDAP=yes
.endif

.if !defined(WITHOUT_LDAP) && defined(WITH_LDAP)
USE_OPENLDAP=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.if !defined(WITH_SENDMAIL_BASE) && \
    !defined(WITH_SENDMAIL_PORT) && \
WITH_SENDMAIL_BASE=yes
.endif

.if defined(WITH_SENDMAIL_BASE)
.if exists(/usr/lib/libmilter.a)
MILTERBASE=	/usr
.else
IGNORE=	base system sendmail not found or too old, rebuild with WITH_SENDMAIL_PORT=yes
.endif
.endif

.if defined(WITH_SENDMAIL_PORT)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/sendmail
MILTERBASE?=	${LOCALBASE}
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS ChangeLog NEWS README TODO
.endif

MILTERINC=	${MILTERBASE}/include
MILTERLIB=	${MILTERBASE}/lib

CPPFLAGS+=	-I${MILTERINC}
LDFLAGS+=	-L${MILTERLIB}

USE_RC_SUBR=	spamass-milter
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

SUB_FILES=	pkg-message

MAN1=		spamass-milter.1

pre-patch:

.if !defined(WITH_SENDMAIL_PORT)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "By default, ${PORTNAME} builds against the base system."
	@${ECHO_CMD} "If you want to use the sendmail port please set the environment"
	@${ECHO_CMD} "variable WITH_SENDMAIL_PORT"
	@${ECHO_CMD} ""
.endif

.if !defined(WITH_ADDAUTH_PATCH)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You may set environment variable WITH_ADDAUTH_PATCH to bypass"
	@${ECHO_CMD} "checks if a connection authenticated via SMTP."
	@${ECHO_CMD} ""
.endif

.if !defined(WITH_REJECTTEXT_PATCH)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You may set environment variable WITH_REJECTTEXT_PATCH to be"
	@${ECHO_CMD} "able to customize the SMTP reject message."
	@${ECHO_CMD} ""
.endif

post-patch:
	@${SED} -e's,%%PREFIX%%,${PREFIX},g' \
		${FILESDIR}/activation.txt > ${WRKDIR}/activation.txt
.if !defined(WITHOUT_LDAP) && defined(WITH_LDAP)
	@${REINPLACE_CMD} -e 's|-lmilter|-lmilter -lldap|g' ${WRKSRC}/configure
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/activation.txt ${DOCSDIR}/activation.txt
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
