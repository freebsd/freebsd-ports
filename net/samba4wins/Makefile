# New ports collection makefile for:	samba4wins
# Date created:				11th Apr 2006
# Whom:					Timur I. Bakeyev <timur@gnu.org>
#
# $FreeBSD$
#

PORTNAME=		samba4wins
PORTVERSION=		1.0.7
PORTREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://ftp.sernet.de/pub/samba4WINS/debian/pool/
DISTNAME=		${PORTNAME}_${PORTVERSION}-2

MAINTAINER=		timur@FreeBSD.org
COMMENT=		A full featured replicating WINS server for UNIX

CONFLICTS=		ja-samba-2.* ja-samba-4.* samba-2.* samba-4.* sharity-light-1.*

USE_ICONV=		yes
USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_AUTOTOOLS=		autoconf:262 autoheader:262

WRKSRC=			${WRKDIR}/${PORTNAME}/source

# directories
VARDIR?=		/var
S4W_DATADIR=		${PREFIX}/share/${PORTNAME}
S4W_LOGDIR=		${VARDIR}/log/${PORTNAME}
S4W_RUNDIR=		${VARDIR}/run
S4W_LOCKDIR=		${VARDIR}/db/${PORTNAME}
S4W_PRIVATE=		${S4W_LOCKDIR}/private
S4W_CONFDIR=		${PREFIX}/etc
S4W_LIBDIR=		${PREFIX}/lib/${PORTNAME}
S4W_CONFIG=		${S4W_CONFDIR}/samba4wins.conf

CONFIGURE_ARGS+=	--exec-prefix=${PREFIX} \
			--datadir=${S4W_DATADIR} \
	    		--libdir=${S4W_LIBDIR} \
			--localstatedir=${VARDIR} \
			--with-privatedir=${S4W_PRIVATE} \
			--with-lockdir=${S4W_LOCKDIR} \
			--with-piddir=${S4W_RUNDIR} \
			--with-logfilebase=${S4W_LOGDIR}

CONFIGURE_ARGS+=	--disable-reg-gconf --disable-socket-wrapper \
			--with-readline=/usr --with-included-popt \
			--with-libiconv=${LOCALBASE} --without-sqlite3 \
			--without-pthreads --without-python

USE_RC_SUBR=		smbd4wins
SUB_LIST+=		S4W_RUNDIR=${S4W_RUNDIR}

PLIST_SUB+=		S4W_LOGDIR=${S4W_LOGDIR} \
			S4W_LOCKDIR=${S4W_LOCKDIR}

INSTALL_TARGET=		showlayout installbin installdat installmisc installlib installpc

post-build:
			@for f in ${WRKSRC}/scripting/bin/*; do \
			    ${REINPLACE_CMD} -i '' -e 's|smbscript|${PREFIX}/bin/smbscript4|' \
				$${f} && ${MV} $${f} $${f}4; \
			done

post-install:
			@${MKDIR} ${S4W_CONFDIR}
			${INSTALL_DATA} ${FILESDIR}/samba4wins.conf.sample ${S4W_CONFDIR}
.if !defined(NOPORTDOCS)
			@${MKDIR} ${DOCSDIR}
.	for d in HOWTO.txt NEWS.txt README.txt TODO.txt
			${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/${PORTNAME}-${d} ${DOCSDIR}/${d}
.	endfor
.endif

.include <bsd.port.mk>
