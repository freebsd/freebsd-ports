# New ports collection makefile for:	mailman
# Date created:		10 July 2000
# Whom:			n_hibma@qubesoft.com
#
# $FreeBSD$
#

PORTNAME=	mailman
PORTVERSION=	1.1
CATEGORIES=	mail
MASTER_SITES=   ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	mailman
DISTNAME=       ${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS+=	python:${PORTSDIR}/lang/python
RUN_DEPENDS+=	$(LOCALBASE)/sbin/httpd:${PORTSDIR}/www/apache13\
		python:${PORTSDIR}/lang/python

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-mail-gid=daemon

UNAME=		mailman
UID=		89

MAILMANDIR=	${PREFIX}/mailman

pre-configure:
	# Add the username, uid, group amd gid
	${SH} ${FILESDIR}/configure.sh ${UNAME} ${UID}

	# Create the dir and the correct permissions for it.
	${MKDIR} ${MAILMANDIR}
	${CHOWN} ${UNAME}:${UNAME} ${MAILMANDIR}
	${CHMOD} g+s ${MAILMANDIR}

post-install:
	@echo All related binaries have been installed in ${MAILMANDIR}/bin
	@echo See ${WORKDIR}/INSTALL for installation instructions \($$prefix == ${MAILMANDIR}\).
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
