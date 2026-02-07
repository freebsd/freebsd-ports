divert(-1)
#
# Copyright (c) 2000 Claus Assmann <ca+popauth@mine.informatik.uni-kiel.de>
#
# In short: you can do whatever you want with this, but don't blame me!
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#
# <URL: http://www.sendmail.org/~ca/email/chk-89n.html >
#
VERSIONID(`$Id: popauth.m4,v 1.5 2000/10/19 17:47:53 ca Exp $')

LOCAL_CONFIG
ifdef(`DATABASE_MAP_TYPE', `', `define(`DATABASE_MAP_TYPE', `hash')')
Kpopauth ifelse(defn(`_ARG_'), `',
		`DATABASE_MAP_TYPE -a<OK> /etc/mail/popauth',
		`_ARG_')
ifdef(`CF_LEVEL', `dnl has been introduced in 8.10
dnl this can be used to add a tag to entries in the map
dnl to restrict the access
ifdef(`POP_B4_SMTP_TAG',, `define(`POP_B4_SMTP_TAG', `POP:')')dnl
ifdef(`POP_TO', `dnl
ifdef(`_ARITH_MAP_', `', `dnl
define(`_ARITH_MAP_', `1')dnl
Karith arith')
')', `dnl
define(`POP_B4_SMTP_TAG', `')dnl
')dnl
LOCAL_RULESETS
SLocal_check_rcpt
R$*		$: $(popauth `'$&{client_addr} $: <?> $)
R<?>		$@ NoPopAuth
ifdef(`POP_TO', `dnl
R$+		$: $(arith - $@ $&T $@ $1 $)
R$+		$: $(arith l $@ $1 $@ POP_TO $)
RFALSE		$@ NoPopAuth
RTRUE		$# OK', `
R$*<OK>		$# OK')
