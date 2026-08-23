--- internal/fido/fido.go.orig	2026-07-26 08:31:48 UTC
+++ internal/fido/fido.go
@@ -15,7 +15,7 @@
 // You should have received a copy of the GNU General Public License
 // along with Proton Mail Bridge. If not, see <https://www.gnu.org/licenses/>.
 
-//go:build darwin || linux
+//go:build darwin || linux || freebsd
 
 package fido
 
