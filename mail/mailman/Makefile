# New ports collection makefile for:	mailman
# Date created:		10 July 2000
# Whom:			n_hibma@qubesoft.com
#
# $FreeBSD$
#

PORTNAME=	mailman
PORTVERSION=	2.0.3
CATEGORIES=	mail
MASTER_SITES=   ${MASTER_SITE_GNU} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mailman
EXTRACT_SUFX=	.tgz

MAINTAINER=	demon@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13

HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${MAILMANDIR} \
		--with-mail-gid=daemon --with-cgi-gid=nogroup
USE_PYTHON=	yes

USERNAME?=	mailman
USERID?=	89

MMDIR?=		mailman
MAILMANDIR=	${PREFIX}/${MMDIR}

pre-configure:
	# Add the username, uid, group and gid
	${SH} ${FILESDIR}/configure.sh ${USERNAME} ${USERID} ${MAILMANDIR}

	# Create the dir and the correct permissions for it.
	${MKDIR} ${MAILMANDIR}
	${CHOWN} ${USERNAME}:${USERNAME} ${MAILMANDIR}
	${CHMOD} 2775 ${MAILMANDIR}

post-install:
	@${CHOWN} -R :${USERNAME} ${MAILMANDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mailman
.for f in BUGS FAQ INSTALL NEWS README* UPGRADING
	@${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/mailman
.endfor
.endif
	@echo All related binaries have been installed in ${MAILMANDIR}/bin
	@echo See ${PREFIX}/share/doc/mailman/INSTALL for installation instructions \(prefix == ${MAILMANDIR}\).
	@echo 'Sample entry for httpd.conf for Apache:'
	@echo '  ScriptAlias /mailman/ ${MAILMANDIR}/cgi-bin/'
	@echo '  <Directory ${MAILMANDIR}/cgi-bin/>'
	@echo '     Options FollowSymLinks ExecCGI'
	@echo '	   ... other options ...'
	@echo '  </Directory>'

.include <bsd.port.mk>
