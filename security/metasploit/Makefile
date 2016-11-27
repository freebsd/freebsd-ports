# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	metasploit
PORTVERSION=	4.13.1
CATEGORIES=	security

MAINTAINER=	tanawts@gmail.com
COMMENT=	Exploit-Framework for Penetration-Testing

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	nmap:security/nmap \
		rubygem-activerecord4>=4.2.6:databases/rubygem-activerecord4 \
		rubygem-activesupport4>=4.2.6:devel/rubygem-activesupport4 \
		rubygem-actionpack4>=4.2.6:www/rubygem-actionpack4 \
		rubygem-bcrypt>=0:security/rubygem-bcrypt \
		rubygem-bundler>=0:sysutils/rubygem-bundler \
		rubygem-jsobfu>=0:www/rubygem-jsobfu \
		rubygem-json>=0:devel/rubygem-json \
		rubygem-metasm>=0:devel/rubygem-metasm \
		rubygem-metasploit-concern>=0:security/rubygem-metasploit-concern \
		rubygem-metasploit-credential>=0:security/rubygem-metasploit-credential \
		rubygem-metasploit_data_models>=0:security/rubygem-metasploit_data_models \
		rubygem-metasploit-model>=0:security/rubygem-metasploit-model \
		rubygem-metasploit-payloads>=1.2.1:security/rubygem-metasploit-payloads \
		rubygem-metasploit_payloads-mettle>=0.1.2:security/rubygem-metasploit_payloads-mettle \
		rubygem-msgpack>=0:devel/rubygem-msgpack \
		rubygem-network_interface>=0:net/rubygem-network_interface \
		rubygem-rubyntlm>=0:net/rubygem-rubyntlm \
		rubygem-nokogiri>=0:textproc/rubygem-nokogiri \
		rubygem-packetfu>=0:net/rubygem-packetfu \
		rubygem-pcaprub>=0:net/rubygem-pcaprub \
		rubygem-pg>=0:databases/rubygem-pg \
		rubygem-railties4>=4.2.6:www/rubygem-railties4 \
		rubygem-recog>=0:security/rubygem-recog \
		rubygem-openssl-ccm>=0:security/rubygem-openssl-ccm \
		rubygem-octokit>=0:net/rubygem-octokit \
		rubygem-redcarpet>=0:textproc/rubygem-redcarpet \
		rubygem-patch_finder>=0:devel/rubygem-patch_finder \
		rubygem-sshkey>=0:security/rubygem-sshkey \
		rubygem-bit-struct>=0:devel/rubygem-bit-struct \
		rubygem-windows_error>=0:devel/rubygem-windows_error \
		rubygem-net-ssh>=0:security/rubygem-net-ssh \
		rubygem-rex-arch>=0.1.2:security/rubygem-rex-arch \
		rubygem-rex-bin_tools>=0:security/rubygem-rex-bin_tools \
		rubygem-rex-core>=0:security/rubygem-rex-core \
		rubygem-rex-encoder>=0:security/rubygem-rex-encoder \
		rubygem-rex-exploitation>=0:security/rubygem-rex-exploitation \
		rubygem-rex-java>=0:security/rubygem-rex-java \
		rubygem-rex-mime>=0:security/rubygem-rex-mime \
		rubygem-rex-nop>=0:security/rubygem-rex-nop \
		rubygem-rex-ole>=0:security/rubygem-rex-ole \
		rubygem-rex-powershell>=0:security/rubygem-rex-powershell \
		rubygem-rex-random_identifier>=0:security/rubygem-rex-random_identifier \
		rubygem-rex-registry>=0:security/rubygem-rex-registry \
		rubygem-rex-rop_builder>=0:security/rubygem-rex-rop_builder \
		rubygem-rex-socket>=0:security/rubygem-rex-socket \
		rubygem-rex-sslscan>=0:security/rubygem-rex-sslscan \
		rubygem-rex-struct2>=0:security/rubygem-rex-struct2 \
		rubygem-rex-text>=0:security/rubygem-rex-text \
		rubygem-rex-zip>=0:security/rubygem-rex-zip \
		rubygem-robots>=0:www/rubygem-robots \
		rubygem-rubyzip>=0:archivers/rubygem-rubyzip \
		rubygem-sqlite3>=0:databases/rubygem-sqlite3 \
		rubygem-tzinfo>=0:devel/rubygem-tzinfo \
		rubygem-filesize>=0:devel/rubygem-filesize \
		rubygem-openvas-omp>=0:security/rubygem-openvas-omp \
		rubygem-nessus_rest>=0:security/rubygem-nessus_rest

SCRIPTS=	msfconsole msfd msfrpc msfrpcd msfvenom

USE_GITHUB=	yes
GH_ACCOUNT=	rapid7
GH_PROJECT=	metasploit-framework

NO_ARCH=	yes
STRIP=

USE_RUBY=	yes

post-patch:
	${REINPLACE_CMD} 's,git ls-files,find . ! -type d | sed "s|^./||", ; \
		/rb-readline-r7/d ; /tzinfo-data/d' \
		${WRKSRC}/metasploit-framework.gemspec

do-build:
	${RM} ${WRKSRC}/Gemfile.lock
	${TOUCH} ${WRKSRC}/Gemfile.lock
	${REINPLACE_CMD} '/^group :coverage/,/^end/d ; /^group :development/,/^end/d ; /^group :test/,/^end/d' \
		${WRKSRC}/Gemfile

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${PAX} -rw . ${STAGEDIR}${DATADIR}
.for f in ${SCRIPTS}
	${LN} -s ../${DATADIR_REL}/${f} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

post-install:
	@${FIND} ${STAGEDIR} ! -type d | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; /Gemfile.lock/s|^|@(,,0666) |' >> ${TMPPLIST}
	@${FIND} -ds ${STAGEDIR}${DATADIR} -type d -empty | \
		${SED} 's,${STAGEDIR}${PREFIX}/,, ; s,^,@dir ,' >> ${TMPPLIST}

.include <bsd.port.mk>
