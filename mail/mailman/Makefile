# New ports collection makefile for:	mailman
# Date created:		10 July 2000
# Whom:			n_hibma@qubesoft.com
#
# $FreeBSD$
#

PORTNAME=	mailman
PORTVERSION=	2.0b5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=   http://download.sourceforge.net/mailman/
DISTNAME=       mailman-2.0beta5
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS+=	python:${PORTSDIR}/lang/python
RUN_DEPENDS+=	$(LOCALBASE)/sbin/httpd:${PORTSDIR}/www/apache13\
		python:${PORTSDIR}/lang/python

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-mail-gid=daemon --with-cgi-gid=nogroup

UNAME=		mailman
UID=		89

MAILMANDIR=	${PREFIX}/mailman

pre-configure:
	# Add the username, uid, group amd gid
	${SH} ${FILESDIR}/configure.sh ${UNAME} ${UID}

	# Create the dir and the correct permissions for it.
	${MKDIR} ${MAILMANDIR}
	${CHOWN} ${UNAME}:${UNAME} ${MAILMANDIR}
	${CHMOD} 2775 ${MAILMANDIR}

post-install:
	@${CHOWN} -R :${UNAME} ${MAILMANDIR}
	@echo All related binaries have been installed in ${MAILMANDIR}/bin
	@echo See ${WRKDIR}/INSTALL for installation instructions \($$prefix == ${MAILMANDIR}\).
	@echo Sample entry for httpd.conf for Apache:
	@echo "  ScriptAlias /mailman/ ${MAILMANDIR}/cgi-bin/"
	@echo '  <Directory ${MAILMANDIR}/cgi-bin/>'
	@echo '     Options FollowSymLinks ExecCGI'
	@echo '	   ... other options ...'
	@echo '  </Directory>'

.include <bsd.port.mk>

# Override the prefix (it is being abused in mailman)
# XXX It might be a good idea to have a look again at where
# the various files are put
CONFIGURE_ARGS+=	--prefix=${MAILMANDIR}
